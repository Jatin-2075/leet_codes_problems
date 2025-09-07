#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int found = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] < found){
                found = nums[mid];
            }
            else if (nums[mid] > nums[mid+1]){
                if(found > nums[mid]) found = nums[mid + 1];
                low = mid + 1;
            }
            else {
                high = mid - 1; 
            }
            return found;
        }
    }
};

int main() {
    vector <int> nums = {3,4,5,1,2};
    Solution s;
    cout << s.findMin(nums);
}