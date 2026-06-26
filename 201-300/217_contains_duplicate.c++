#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>sets;

        for(int i = 0; i < nums.size(); i++){
            if(sets.find(nums[i]) != sets.end()){
                return true;
            }
            sets.insert(nums[i]);
        }
        return false;
    }
};

int main(){
    vector<int>nums = {1,1,1,1,1};
    Solution s;
    cout << s.containsDuplicate(nums);
}