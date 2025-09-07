#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sol(vector<int> nums) {
        int ov = 0;
        int largest = 0;
        
        for (int n = 0; n < nums.size(); ++n) {
            if (nums[n] == 1) {
                ov++;
                largest = max(largest, ov);
            } else {
                ov = 0;
            }
        }
        return largest;
    }
};

int main() {
    vector<int> nums = {1,0,1,1,1,0,0,1};
    Solution s;
    cout << s.sol(nums);
}
