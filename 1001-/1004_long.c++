#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int kth = 0 , lenght = 0, ans = 0;

        int left = 0, right = 0;
        
        while(right < nums.size()){
            if(nums[right] == 0){
                kth++;
            }

            if(kth > k){
                while(kth > k){
                    if(nums[left] == 0){
                        kth--;
                    }
                    lenght--;
                    left++;
                }
            }
            lenght++;
            right++;

            ans = max(lenght, ans);
        }

        return ans;
    }
};

int main() {

    vector <int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;

    Solution sol;
    cout << sol.longestOnes(nums, k);
}