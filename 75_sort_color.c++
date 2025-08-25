#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int n = 0; n < nums.size(); n++){
            int min = n;
            for(int j = n + 1; j < nums.size(); j++){
                if(nums[j] < nums[min]){
                    min = j ;
                }
            }
            swap(nums[n], nums[min]);
        }
    }
};

int main() {
    vector <int> nums = {2,0,1};
    Solution s;
    s.sortColors(nums);

    for(auto it : nums){
        cout << it << " , ";
    }
}