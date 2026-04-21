#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int > mpp;

        for(int num : nums2){
            while(!s.empty() && s.top() < num){
                mpp[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        while(!s.empty()){
            mpp[s.top()] = -1;
            s.pop();
        }
        vector<int> ans;
        for(int num : nums1) ans.push_back(mpp[num]);
        return ans;
    }
};

int main() {

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    Solution sol;

    vector<int> res = sol.nextGreaterElement(nums1, nums2);

    for(int x : res) {
        cout << x << " ";
    }

    return 0;
}
