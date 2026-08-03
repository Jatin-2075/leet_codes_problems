#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest)
                return false;

            farthest = max(farthest, i + nums[i]);
        }

        return true;
    }
};

int main() {
    Solution s;

    vector<int> nums = {2, 3, 1, 1, 4};

    if (s.canJump(nums))
        cout << "true";
    else
        cout << "false";

    return 0;
}