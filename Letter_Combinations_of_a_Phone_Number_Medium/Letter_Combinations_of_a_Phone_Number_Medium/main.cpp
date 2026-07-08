//
//  main.cpp
//  Letter_Combinations_of_a_Phone_Number_Medium
//
//  Created by Vu Cao Nguyen on 8/7/26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> result;

string path;

string phone[] = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void backtrack(string digits, int index) {
    if (index == digits.size()) {
        result.push_back(path);
        return;
    }
    
    string letters = phone[digits[index] - '0'];
    
    for (char c : letters) {
        path += c;
        backtrack(digits, index + 1);
        path.pop_back();
    }
}

int main() {
    string digits;
        cin >> digits;

        if (digits.empty()) {
            cout << "[]";
            return 0;
        }

        backtrack(digits, 0);

        cout << "[";
        for (int i = 0; i < result.size(); i++) {
            cout << "\"" << result[i] << "\"";
            if (i != result.size() - 1)
                cout << ", ";
        }
        cout << "]";

        return 0;
}
