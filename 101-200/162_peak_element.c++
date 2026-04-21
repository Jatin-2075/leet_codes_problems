#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid + 1] < nums[mid] && nums[mid] > nums[mid - 1]){
                return nums[mid - 1];
            }
            else if(nums[mid + 1] > nums[mid]){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
};

int main() {
    vector <int> nums = {1,2,3,1};
    Solution s;
    cout << s.findPeakElement(nums);
}