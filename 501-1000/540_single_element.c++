#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        bool check = true;

        while(check){
            int mid = low + (high - low) / 2;

            if(nums[mid+1] > nums[mid] && nums[mid-1] < nums[mid]){
                return nums[mid];
                check = false;
            }

            else if(low < high){
                high = mid - 1;
            }
            else if(high == low){
                high = nums.size();
            }
        }
    }
};

int main() {
    vector <int> nums = {1,1,2,3,3,4,4,8,8};

    Solution s;
    cout << s.singleNonDuplicate(nums);
}