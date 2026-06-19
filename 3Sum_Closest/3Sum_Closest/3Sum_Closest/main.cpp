//
//  main.cpp
//  3Sum_Closest
//
//  Created by Nguyen on 19/6/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

    class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int closest = nums[0] + nums[1] + nums[2];
            
            for (int i = 0; i < nums.size() - 2; i++) {
                int left = i + 1;
                int right = (int)nums.size() - 1;
                
                while (left < right) {
                    int sum = nums[i] + nums[left] + nums[right];
                    
                    if (abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }
                    
                    if (sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        return sum;
                    }
                }
            }
            return closest;
        }
    };

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, -1, 2, -4};
    int target1 = 1;
    
    cout << "Test 1: " << sol.threeSumClosest(nums1, target1) << endl;
    
    vector<int> nums2 = {2, 3, 1, -5};
    int target2 = 100;
    
    cout << "Test 2: " << sol.threeSumClosest(nums2, target2) << endl;
}
