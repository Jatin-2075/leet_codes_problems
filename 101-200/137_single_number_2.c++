#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;

        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }

        return ones;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {2, 2, 3, 2};

    cout << obj.singleNumber(nums) << endl;

    return 0;
}