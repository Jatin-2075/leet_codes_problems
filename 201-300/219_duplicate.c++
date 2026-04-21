#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for(int n = 0; n < nums.size(); ++n){
            if(set.count(nums[n])) return true;
            set.insert(nums[n]);
            if(set.size() > k){
                set.erase(nums[n-k]);
            }
        }
        return false;
    }
};

int main(){
    vector <int> nums = {1,2,3,1};
    int k = 3;
    Solution s;
    cout << s.containsNearbyDuplicate(nums, k);
}