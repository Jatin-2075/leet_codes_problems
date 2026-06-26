#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s;
        vector<int> ans;

        for (int num : nums) {
            s.insert(num);
        }

        for (int i = 1; i <= nums.size(); i++) {
            if (s.find(i) == s.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    Solution s;
    vector<int> ans = s.findDisappearedNumbers(nums);

    cout << "Missing numbers: ";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}