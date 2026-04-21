#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, ans = 0;
        int minlen = INT_MAX;

        for(int n = 0; n < nums.size(); ++n){
            ans += nums[n];
            
            while(target <= ans){
                minlen = min(minlen, n - left + 1);
                ans -= nums[left];
                left++;
            }
        }
        return (minlen == INT_MAX) ? 0 : minlen;
    }
};

int main() {
    int target = 4;
    vector<int> nums = {1,4,4};
    Solution s;
    cout << s.minSubArrayLen(target, nums);
}