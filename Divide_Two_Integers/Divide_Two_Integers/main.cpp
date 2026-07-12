//
//  main.cpp
//  Divide_Two_Integers
//
//  Created by Vu Cao Nguyen on 12/7/26.
//

#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long a = llabs((long long)dividend);
    long long b = llabs((long long)divisor);

    long long ans = 0;

    for (int i = 31; i >= 0; i--) {
        if ((a >> i) >= b) {
            ans += (1LL << i);
            a -= (b << i);
        }
    }

    if ((dividend < 0) ^ (divisor < 0))
        ans = -ans;

    return (int)ans;
}

int main() {
    int dividend, divisor;

    cout << "Nhap dividend: ";
    cin >> dividend;

    cout << "Nhap divisor: ";
    cin >> divisor;

    if (divisor == 0) {
        cout << "Khong the chia cho 0!" << endl;
        return 0;
    }

    cout << "Ket qua: " << divide(dividend, divisor) << endl;

    return 0;
}
