//
//  main.cpp
//  Generate_Parentheses
//
//  Created by Vu Cao Nguyen on 10/7/26.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> result;
string path;

void backtrack(int open, int close, int n) {
    if (path.size() == 2 * n) {
        result.push_back(path);
        return;
    }

    if (open < n) {
        path.push_back('(');
        backtrack(open + 1, close, n);
        path.pop_back();
    }

    if (close < open) {
        path.push_back(')');
        backtrack(open, close + 1, n);
        path.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    result.clear();
    path.clear();

    backtrack(0, 0, n);

    return result;
}

int main() {
    int n;
    cout << "Nhap n: ";
    cin >> n;

    vector<string> ans = generateParenthesis(n);

    cout << "Cac chuoi ngoac dung:\n";
    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}
