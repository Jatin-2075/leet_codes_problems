#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sorting(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] > nums[(i+1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
};


int main(){
    vector <int> nums = {2,1,3,4};
    Solution s;
    if(s.sorting(nums) == 1){
        cout << "this array is sorted ";
    }
    else {
        cout << " false";
    }
}