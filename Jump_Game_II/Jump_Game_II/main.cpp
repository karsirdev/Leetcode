//
//  main.cpp
//  Jump_Game_II
//
//  Created by Vu Cao Nguyen on 21/7/26.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Output: " << solution.jump(nums1) << endl;

    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Output: " << solution.jump(nums2) << endl;

    return 0;
}
