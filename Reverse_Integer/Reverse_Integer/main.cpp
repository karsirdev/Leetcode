//
//  main.cpp
//  Reverse_Integer
//
//  Created by Vu Cao Nguyen on 5/7/26.
//

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        
        while (x != 0) {
            int digit = x % 10;\
            x /= 10;
            
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) {
                return 0;
            }
            
            rev = rev * 10 + digit;
        }
        return rev;
    }
};

int main() {
    Solution sol;
    
    cout << sol.reverse(123) << endl;
    cout << sol.reverse(-123) << endl;
    cout << sol.reverse(0) << endl;
    
    return 0;
}
