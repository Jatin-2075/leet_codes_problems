#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void Rotation(vector<int> &nums){
        int pos = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[pos] = nums[i];
                pos++;
            }
        }
        while(pos < nums.size()){
            nums[pos] = 0;
            pos++;
        }
    }
};


int main(){
    vector <int> nums = {0,0,1};
    Solution s;
    s.Rotation(nums);
    for(int n = 0; n < nums.size(); ++n){
        cout << nums[n] << " ";
    }
}