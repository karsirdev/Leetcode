//
//  main.swift
//  Merge_Intervals
//
//  Created by Vu Cao Nguyen on 22/10/26.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    for (auto& cur : intervals) {
        if (res.empty() || res.back()[1] < cur[0]) {
            res.push_back(cur);
        } else {
            res.back()[1] = max(res.back()[1], cur[1]);
        }
    }
    return res;
}

void printIntervals(const vector<vector<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]\n";
}

int main() {
    vector<vector<vector<int>>> tests = {
        {{1,3},{2,6},{8,10},{15,18}},  // expect [[1,6],[8,10],[15,18]]
        {{1,4},{4,5}},                 // expect [[1,5]]
        {{1,10},{2,5}},                // expect [[1,10]]
        {{5,6},{1,2},{2,3}},           // chưa sort sẵn -> [[1,3],[5,6]]
        {{7,8}}                        // 1 đoạn -> [[7,8]]
    };

    for (auto& t : tests) {
        cout << "Input : ";
        printIntervals(t);
        auto result = merge(t);
        cout << "Output: ";
        printIntervals(result);
        cout << "---\n";
    }
    return 0;
}

