#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int x : nums) {
            if (x <= first) {
                first = x;
            }
            else if (x <= second) {
                second = x;
            }
            else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    if (sol.increasingTriplet(nums))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}