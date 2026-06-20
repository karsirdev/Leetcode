//
//  main.cpp
//  Container With Most Water
//
//  Created by Vu Cao Nguyen on 20/6/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = (int)height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};

int main() {
    Solution sol;
    
    vector<int> test1 = {1, 8, 7, 5, 3, 2, 3, 9, 6, 5};
    cout << "Test 1: " << sol.maxArea(test1) << endl;
    
    vector<int> test2 = {1, 1};
    cout << "Test 2: " << sol.maxArea(test2) << endl;
}
