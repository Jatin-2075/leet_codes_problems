#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 ;
        int max_num = INT_MIN;
        for(int n = 0; n < nums.size(); ++n){
            sum += nums[n];
            max_num = max(max_num, sum);
            if(sum < 0) sum = 0;
        }  
        return max_num;
    }
};

int main() {
    vector <int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums);
}