//
//  main.cpp
//  Merge Sorted Array
//
//  Created by Nguyen on 14/6/26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        while (p2 >= 0) {
            if (p1 >= 0 && nums1[p1] >= nums2[p2]) {
                nums1[p--] = nums1[p1--];
            } else {
                nums1[p--] = nums2[p2--];
            }
        }
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    
    sol.merge(nums1, 3, nums2, 3);
    
    for(int x : nums1) cout << x << " ";
    
    return 0;
}
