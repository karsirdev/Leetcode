//
//  main.cpp
//  Group_Anagrams
//
//  Created by Vu Cao Nguyen on 26/7/26.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto &it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (auto &group : result) {
        cout << "[ ";
        for (auto &word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
