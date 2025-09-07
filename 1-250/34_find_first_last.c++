#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowha(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int found = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > target) {
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                found = mid;
                high = mid - 1;
            }
        }
        return found;
    }

    int highha(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int first = lowha(nums, target);
        int last = highha(nums, target);
        return {first, last};
    }
};

int main() {
    vector<int> nums = {0,1,1,1,2};
    int target = 1;

    Solution s;
    vector<int> result = s.searchRange(nums, target);

    for (auto it : result) {
        cout << it << " ";
    }
}
