#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int finder(vector <int> nums){
        map <int, int> freq ;
        for(int n = 0; n < nums.size(); ++n){
            freq[nums[n]]++;
        }
        int smallest = INT_MAX;
        int found = 0;

        for(auto x : freq){
            if (x.second < smallest) {
                smallest = x.second;
                found = x.first; 
            }
        }
         
        return found;
    }
};

int main() {
    vector <int> nums = {2,2,1};
    Solution s;
    cout << s.finder(nums);
}