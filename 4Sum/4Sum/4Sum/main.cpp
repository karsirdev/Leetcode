//
//  main.cpp
//  4Sum
//
//  Created by Vu Cao Nguyen on 20/6/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    auto res1 = sol.fourSum(nums1, 0);
    cout << "Test 1:" << endl;
    for (auto& v : res1)
        cout << "[" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "]" << endl;

    vector<int> nums2 = {2, 2, 2, 2, 2};
    auto res2 = sol.fourSum(nums2, 8);
    cout << "Test 2:" << endl;
    for (auto& v : res2)
        cout << "[" << v[0] << "," << v[1] << "," << v[2] << "," << v[3] << "]" << endl;

    return 0;
}
