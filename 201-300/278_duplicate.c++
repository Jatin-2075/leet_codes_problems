#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int, int>mpp;

//         for(int i = 0; i < nums.size(); i++){
//             mpp[nums[i]]++;

//             if(mpp[nums[i]] == 2)return nums[i];
//         }
//         return 0;
//     }
// };

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        unordered_map<int, int> mpp;

        while (left <= right)
        {

            mpp[nums[left]]++;
            if (mpp[nums[left]] >= 2)
                return nums[left];

            if (left != right)
            {
                mpp[nums[right]]++;
                if (mpp[nums[right]] >= 2)
                    return nums[right];
            }

            left++;
            right--;
        }
        return 0;
    }
};

int main()
{
    vector<int> nums = {1, 2, 3, 4, 1};
    Solution s;
    cout << s.findDuplicate(nums);
}