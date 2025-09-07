#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxprod = nums[0], minprod = nums[0], ans = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < 0) swap(minprod, maxprod);

            maxprod = max(nums[i], maxprod*nums[i]);
            minprod = min(nums[i], minprod*nums[i]);

            ans = max(maxprod , ans);
        }
        return ans;
    }
};

int main() {
    vector <int> nums = {2,3,-2,4};
    Solution s;
    cout << s.maxProduct(nums);
}