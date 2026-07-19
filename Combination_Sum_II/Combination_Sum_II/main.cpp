//
//  main.cpp
//  Combination_Sum_II
//
//  Created by Vu Cao Nguyen on 19/7/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void backtrack(vector<int>& candidates, int target, int start) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Bỏ qua các phần tử trùng ở cùng một mức
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);
            // i + 1 vì mỗi số chỉ được sử dụng một lần
            backtrack(candidates, target - candidates[i], i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans;
    }
};

int main() {
    Solution solution;

    vector<int> candidates;
    int n, target;

    cout << "Nhap so luong phan tu: ";
    cin >> n;

    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        candidates.push_back(x);
    }

    cout << "Nhap target: ";
    cin >> target;

    vector<vector<int>> result = solution.combinationSum2(candidates, target);

    cout << "\nCac to hop thoa man:\n";

    if (result.empty()) {
        cout << "Khong co to hop nao.\n";
    } else {
        for (const auto &combination : result) {
            cout << "[ ";
            for (int num : combination) {
                cout << num << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}
