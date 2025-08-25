#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sorting_alternate(vector<int> &nums) {
        vector <int> pos;
        vector <int> neg;
        vector <int> sorted;

        for(int n = 0; n < nums.size(); ++n){
            if(nums[n] > 0) pos.push_back(nums[n]);
            else neg.push_back(nums[n]);
        }

        int n = 0;
        int j = 0;
        bool status = true;

        while(n < pos.size() || j < neg.size()){
            if(status && n < pos.size()){
                sorted.push_back(pos[n++]);
            }
            else {
                sorted.push_back(neg[j++]);
            }
            status = !status;
        }
        return sorted;
    }
};

int main() {
    vector<int> nums = {1,1,-1,-1};
    Solution s;

    vector<int> res = s.sorting_alternate(nums);

    for (int x : res) {
        cout << x << " ";
    }
}