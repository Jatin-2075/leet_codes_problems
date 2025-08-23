#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int , int> mymap;

        for(auto n : nums){
            mymap[n]++;
        }
        int max = 0;
        int number = 0;

        for(auto n : mymap){
            if(max < n.second){
                max = n.second;
                number = n.first;
            }
        }
        return number;
    }
};

int main() {
    vector <int> nums = {3,2,3};
    Solution s;
    cout << s.majorityElement(nums);
}