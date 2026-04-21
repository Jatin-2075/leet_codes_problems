#include <bits/stdc++.h>
using namespace std;
 

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int i, vector<int>& nums){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        dfs(i+1, nums);

        curr.pop_back();
        dfs(i+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};


int main(){
    vector<int> nums = {1,2,3,4,5,6};
    Solution s;

    vector<vector<int>> ans = s.subsets(nums);

    for(int i = 0; i < ans.size(); i++){
        cout << "[ ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "]\n";
    }
}   