//
//  main.cpp
//  String_to_Integer_(atoi)
//
//  Created by Vu Cao Nguyen on 6/7/26.
//

#include <iostream>
#include <string>
#include <climits>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = (int)s.size();
        
        while (i < n && s[i] == ' ') {
            i++;
        }
        
        if (i == n) {
            return 0;
        }
        
        int sign = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        
        long long num = 0;
        
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            
            if (sign == 1 && num > INT_MAX) {
                return INT_MAX;
            }
            if (sign == -1 && -num < INT_MIN) {
                return INT8_MIN;
            }
            i++;
        }
        return static_cast<int>(sign * num);
    }
};

int main() {
    Solution sol;
    
    cout << sol.myAtoi("42") << endl;                // 42
    cout << sol.myAtoi("   -42") << endl;            // -42
    cout << sol.myAtoi("4193 with words") << endl;   // 4193
    cout << sol.myAtoi("words and 987") << endl;     // 0
    
    return 0;
}
