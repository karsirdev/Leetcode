//
//  main.cpp
//  Longest_Substring_Without_Repeating_Characters
//
//  Created by Vu Cao Nguyen on 4/7/26.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < s.size(); right++) {
            if (last.count(s[right])) {
                left = max(left, last[s[right]] + 1);
            }
            
            last[s[right]] = right;
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    string s;
    cin >> s;
    
    cout << sol.lengthOfLongestSubstring(s) << endl;
    
    return 0;
}
