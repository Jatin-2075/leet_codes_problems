#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, going_process = 1;

        int left = 0, right = 0;

        while(right < nums.size()){
            going_process *= nums[right];

            while(going_process >= k && left <= right){
                going_process /= nums[left];
                left++;
            }

            ans += right - left + 1;
            right++;

        }

        return ans;
    }
};

int main() {
    vector <int> nums = {10,6,8,4};
    int k = 100;

    Solution s;

    cout << s.numSubarrayProductLessThanK(nums, k);
}