//
//  main.cpp
//  Integer_to_Roman
//
//  Created by Vu Cao Nguyen on 7/7/26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string intToRoman(int num) {
    vector<pair<int, string>> roman = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    
    string ans;
    
    for (auto &[value, symbol] : roman) {
        while (num >= value) {
            ans += symbol;
            num -= value;
        }
    }
    return ans;
}

int main() {
    int num;
    cout << "Nhập số nguyên (1 - 3999): ";
    cin >> num;
    
    if (num < 1 || num > 3999) {
        cout << "Số nguyên không hợp lệ" << endl;
        return 0;
    }
    
    cout << "Roman: " << intToRoman(num) << endl;
    
    return 0;
}
