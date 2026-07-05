//
//  main.cpp
//  Longest_Palindromic_Substring
//
//  Created by Vu Cao Nguyen on 5/7/26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        int start = 0, maxLen = 1;
        
        
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        };
        
        for (int i = 0; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl;
    cout << sol.longestPalindrome("cbbd") << endl;
    cout << sol.longestPalindrome("a") << endl;
    
    return 0;
}
