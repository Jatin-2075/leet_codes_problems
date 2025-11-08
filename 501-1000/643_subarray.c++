#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int size = nums.size();
        long long avg = 0;
        for(int n = 0; n < k; ++n){
            avg += nums[n];
        }
        long long ans =avg;
        for(int n = 1; n < size - k + 1; ++n ){
            avg = avg - nums[n-1] + nums[n + k - 1];
            if(ans < avg){
                ans = avg;
            }
        }
        return (double)ans / k;
    }
};

int main() {
    vector <int> nums = {1,12,-5,-6,50,3};
    int k = 4;

    Solution s;
    cout << s.findMaxAverage(nums, k);
    return 0;
}