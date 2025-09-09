#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> maps;
        vector <int> found;

        for(int n = 0; n < nums.size(); ++n){
            maps[nums[n]]++;

            if(maps[n] == nums.size() / 3){
                found.push_back(nums[n]);
            }
        }
        
        return found;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 2, 2};
    vector<int> result = sol.majorityElement(nums);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

