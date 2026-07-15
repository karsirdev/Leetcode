//
//  main.cpp
//  Count_and_Say
//
//  Created by Vu Cao Nguyen on 15/7/26.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n){
        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;
            
            for (int j = 1; j <= result.size(); j++) {
                if (j < result.size() && result[j] == result[j - 1]) {
                    count++;
                } else {
                    temp += to_string(count);
                    temp += result[j - 1];
                    count = 1;
                }
            }
            result = temp;
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    int n;
    cin >> n;
    
    cout << sol.countAndSay(n);
    return 0;
}
