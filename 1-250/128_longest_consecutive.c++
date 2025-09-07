#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int found = 1;
        int compare = 1;

        for(int n = 0; n < nums.size()-1; n++){
            int min = n;
            for(int j = n + 1; j < nums.size(); j++){
                if(nums[min] > nums[j]) min = j;
            }
            swap(nums[n] , nums[min]);  
        }

        for(auto it : nums) cout << it << ",";
        cout << "\n";

        for(int n = 1; n < nums.size(); ++n){
            int number = nums[n-1] + 1;
            if(number == nums[n]){
                ++compare;
            }
            else if(nums[n] == nums[n+1]) continue;
            else if(nums[n] != number){
                compare = 1;
            }
            if(compare > found) {
                found = compare;
            }
        }
        return found;
    }
};

int main() {
    vector <int> nums = {1,0,1,2};
    Solution s;
    cout << s.longestConsecutive(nums);
}