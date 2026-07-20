//
//  main.cpp
//  Multiply_Strings
//
//  Created by Vu Cao Nguyen on 20/7/26.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = (int)num1.size();
        int n = (int)num2.size();

        vector<int> res(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];

                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        string ans = "";
        int i = 0;

        while (i < res.size() && res[i] == 0)
            i++;

        while (i < res.size())
            ans += char(res[i++] + '0');

        return ans;
    }
};

int main() {
    Solution sol;

    string num1, num2;

    cout << "Nhap so thu nhat: ";
    cin >> num1;

    cout << "Nhap so thu hai: ";
    cin >> num2;

    cout << "Ket qua: " << sol.multiply(num1, num2) << endl;

    return 0;
}
