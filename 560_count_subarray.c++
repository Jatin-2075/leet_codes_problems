#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;

        for(int i = 0; i < nums.size(); ++i){
            int sum = 0;
            for(int j = i; j < nums.size(); ++j){
                sum = sum + nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};

int main() {
    vector <int> nums = {1,2,1,2,1};
    int k = 3;
    Solution s;
    cout << s.subarraySum(nums, k);
}