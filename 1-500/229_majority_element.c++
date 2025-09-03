#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
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

