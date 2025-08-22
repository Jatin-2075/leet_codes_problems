#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;
        for (int x : nums) sum += x;
        return total - sum;
    }
};

int main() {
    vector<int> nums = {1, 4, 5, 6, 7}; 
    Solution s;
    cout << s.missingNumber(nums);
}
