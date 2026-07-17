//
//  main.cpp
//  Combination_Sum
//
//  Created by Vu Cao Nguyen on 18/7/26.
//

#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<int>& candidates, int target, int start,
               vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    if (target < 0)
        return;

    for (int i = start; i < candidates.size(); i++) {
        current.push_back(candidates[i]);
        backtrack(candidates, target - candidates[i], i, current, result);
        current.pop_back();
    }
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result;
    vector<int> current;

    backtrack(candidates, target, 0, current, result);

    cout << "Combinations:\n";
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
