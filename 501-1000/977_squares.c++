#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector <int> ans(nums.size());

        int k = nums.size() - 1;

        while(left <= right){
            int l = nums[left] * nums[left];
            int r = nums[right] * nums[right];

            if(l > r){
                ans[k--] = l;
                left++;
            }
            else{
                ans[k--] = r;
                right--;
            }
        }

        return ans;
    }
};

int main(){
    vector <int> nums = {-4,-1,0,3,10};

    Solution s;

    vector <int> ans = s.sortedSquares(nums);
}