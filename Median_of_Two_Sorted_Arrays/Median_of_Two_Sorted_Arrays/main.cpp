//
//  main.cpp
//  Median_of_Two_Sorted_Arrays
//
//  Created by Vu Cao Nguyen on 2/11/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        while (left <= right) {
            int partitionX = (left + right) / 2;
            int partitionY = (m + n + 1) / 2 - partitionX;

            int maxLeftX = (partitionX == 0)
                ? INT_MIN : nums1[partitionX - 1];

            int minRightX = (partitionX == m)
                ? INT_MAX : nums1[partitionX];

            int maxLeftY = (partitionY == 0)
                ? INT_MIN : nums2[partitionY - 1];

            int minRightY = (partitionY == n)
                ? INT_MAX : nums2[partitionY];

            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                if ((m + n) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) +
                            min(minRightX, minRightY)) / 2.0;
                }

                return max(maxLeftX, maxLeftY);
            }

            if (maxLeftX > minRightY) {
                right = partitionX - 1;
            } else {
                left = partitionX + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    cout << fixed << setprecision(5);
    cout << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
