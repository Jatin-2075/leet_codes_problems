#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> windows;
        vector<int> ans;

        for (int i = 0; i < k; i++) {
            windows.push_back(nums[i]);
        }

        ans.push_back(*max_element(windows.begin(), windows.end()));

        for (int i = k; i < nums.size(); i++) {

            windows.erase(windows.begin());

            windows.push_back(nums[i]);

            int maxans = *max_element(windows.begin(), windows.end());

            ans.push_back(maxans);
        }

        return ans;
    }
};

int main(){

}