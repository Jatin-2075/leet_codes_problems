#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low < high){
            int mid = (low+high)/2;
            int n = Find_Max_Sum(nums, mid);

            if(n > k){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    };
    int Find_Max_Sum(vector<int>& nums, int mid) {
        int count = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(sum + nums[i] > mid){
                sum = nums[i];
                count++;
            }
            else{
                sum += nums[i];
            }
        }
        return count;
    }
};

int main(){
    vector <int> nums = {7,2,5,10,8};
    int k = 2;

    Solution s;
    cout << s.splitArray(nums, k);
}