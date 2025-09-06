#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int low = 0;
        int high = size - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] <= target){
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
};

int main() {
    vector <int> nums = {0,1,2,4,5,9,12};
    int target = 9;
    Solution s;
    cout << s.search(nums, target);
}