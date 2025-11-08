#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0, left = 0, zerocount = 0;

        for(int right = 0; right < nums.size(); ++right){
            if(nums[right] == 0) zerocount++;

            while(zerocount > 1){
                if(nums[left] == 0) zerocount--;
                left++;
            }
            ans = max(ans , right - left);
        }
        return ans;
    }
};

int main() {
    vector <int> nums = {1,1,0,1};

    Solution s;

    cout << s.longestSubarray(nums);
}