#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void getperm(vector<int>& nums, int i, vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int n = i; n < nums.size(); n++){
            swap(nums[n], nums[i]);    
            getperm(nums, i+1, ans); 
            swap(nums[n], nums[i]);  
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getperm(nums, 0, ans);
        return ans;
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> ans = s.permute(nums);
}