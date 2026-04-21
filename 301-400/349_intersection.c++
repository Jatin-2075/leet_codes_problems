#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) swap(nums1, nums2);
        sort(nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        set<int>ans;
        for(int n = 0; n < nums1.size(); n++){
            int low = 0;
            int high = nums2.size()-1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(nums2[mid] > nums1[n]) high = mid - 1;
                else if (nums2[mid] == nums1[n]){
                    ans.insert(nums1[n]);
                    break;
                }
                else low = mid + 1;
            }
        }
        vector <int> answer(ans.begin(), ans.end());
        return answer;
    }
};

int main(){
    vector <int> num1 = {4,8,9};
    vector <int> num2 = {5,2,4,6,7,9};

    Solution s;
    vector <int> ans = s.intersection(num1, num2);
}