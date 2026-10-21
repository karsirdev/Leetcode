//
//  main.swift
//  Jump_Game
//
//  Created by Vu Cao Nguyen on 22/10/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        int i = 0;
        while (i <= maxReach && i < n) {
            maxReach = max(maxReach, i + nums[i]);
            i++;
        }
        return maxReach >= n - 1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {2, 3, 1, 1, 4},  // true
        {3, 2, 1, 0, 4},  // false
        {0},              // true
        {0, 1}            // false
    };

    for (auto& nums : tests) {
        cout << "[";
        for (size_t k = 0; k < nums.size(); k++) {
            cout << nums[k] << (k + 1 < nums.size() ? "," : "");
        }
        cout << "] -> " << (sol.canJump(nums) ? "true" : "false") << endl;
    }

    return 0;
}
