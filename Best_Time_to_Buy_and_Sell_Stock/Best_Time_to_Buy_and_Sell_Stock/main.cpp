//
//  main.cpp
//  Best_Time_to_Buy_and_Sell_Stock
//
//  Created by Vu Cao Nguyen on 31/8/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

int main() {
    Solution solution;

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = solution.maxProfit(prices);

    cout << "Max Profit: " << result << endl;

    return 0;
}
