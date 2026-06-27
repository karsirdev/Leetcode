//
//  main.cpp
//  Find First and Last Position of Element in Sorted Array
//
//  Created by Vu Cao Nguyen on 27/6/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;
        int result = - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    int findLast(vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;
        int result = - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                result = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
    
};


int main() {
    Solution sol;
    vector<int> nums = {5, 7 ,7 ,8, 8, 10};
    vector<int> res = sol.searchRange(nums, 8);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
