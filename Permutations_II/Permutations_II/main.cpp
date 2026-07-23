//
//  main.cpp
//  Permutations_II
//
//  Created by Vu Cao Nguyen on 23/7/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;

    void backtrack(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // Nếu phần tử đã được sử dụng thì bỏ qua
            if (used[i])
                continue;

            // Bỏ qua các phần tử trùng nhau
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtrack(nums);

            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used.assign(nums.size(), false);

        backtrack(nums);

        return result;
    }
};

int main() {
    Solution solution;

    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Nhap cac phan tu: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = solution.permuteUnique(nums);

    cout << "\nCac hoan vi khong trung nhau:\n";
    for (const auto &perm : ans) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
