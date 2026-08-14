#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);
        vector<int> ans(2);

        for (int num : nums) {
            freq[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2)
                ans[0] = i;
            else if (freq[i] == 0)
                ans[1] = i;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 2, 4};

    vector<int> ans = sol.findErrorNums(nums);

    cout << "Duplicate: " << ans[0] << endl;
    cout << "Missing: " << ans[1] << endl;

    return 0;
}