//
//  main.cpp
//  Pow(x, n)
//
//  Created by Vu Cao Nguyen on 2/9/26.
//

#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;

        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        double result = 1.0;

        while (power > 0) {
            if (power % 2 == 1) {
                result *= x;
            }

            x *= x;
            power /= 2;
        }

        return result;
    }
};

int main() {
    Solution solution;

    double x;
    int n;

    cout << "Nhap x: ";
    cin >> x;

    cout << "Nhap n: ";
    cin >> n;

    cout << x << "^" << n << " = "
         << solution.myPow(x, n) << endl;

    return 0;
}
