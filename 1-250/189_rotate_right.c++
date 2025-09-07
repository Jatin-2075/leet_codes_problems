#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int rotation(vector <int> &nums , int k){
        int n = nums.size();
        k = k % n;

        reverse(nums.begin() , nums.end());
        reverse(nums.begin() , nums.begin() + k);
        reverse(nums.begin() + k , nums.end());
    }
};

int main(){
    int k;
    vector <int> nums = {1,2,3,4,5};
    cout << "hlo\n";
    cin >> k;
    Solution s;
    s.rotation(nums, k);
    cout << k << "after rotation \n";
    for(int n = 0 ; n < nums.size(); ++n){
        cout << nums[n] << " , ";
    }
}