//
//  main.cpp
//  3Sum
//
//  Created by Vu Cao Nguyen on 24/6/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        int n = (int)nums.size();
        
        for(int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    left++;
                    right--;
                    
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Nhập số phần tử: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Nhập các phần tử: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    Solution s;
    vector<vector<int>> ans = s.threeSum(nums);
    cout << "\nKết quả\n";
    
    if (ans.empty()) {
        cout << "Không tồn tại bộ ba nào" << endl;
    } else {
        for (const auto &triplet : ans) {
            cout << "[";
            for (int x : triplet) {
                cout << x << " ";
            }
            cout << "]\n";
        }
    }
    return 0;
}
