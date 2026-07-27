#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> st;

    void backtrack(vector<int>& nums, int idx) {
        if (idx == nums.size()) {
            st.insert(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            backtrack(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        backtrack(nums, 0);

        vector<vector<int>> ans;
        for (auto &v : st) {
            ans.push_back(v);
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;

    Solution s;
    vector<vector<int>> ans = s.permuteUnique(nums);

    return 0;
}