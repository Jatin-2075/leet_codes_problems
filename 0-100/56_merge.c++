#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> nums = {
        {1,3},
        {2,6},
        {8,10},
        {15,18}
    };

    Solution s;
    vector<vector<int>> ans = s.merge(nums);

    for (auto interval : ans) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }

    return 0;
}