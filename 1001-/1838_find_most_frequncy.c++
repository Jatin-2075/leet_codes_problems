#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int l = 0, ans = 1;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];

            while ((long long)nums[r] * (r - l + 1) - sum > k) {
                sum -= nums[l];
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1,2,1,3};
    int k = 2;
    Solution s;
    cout << s.maxFrequency(nums, k);
}
