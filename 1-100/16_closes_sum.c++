#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++)
        {
            int l = i + 1, r = nums.size() - 1;
 
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];

                if (abs(sum - target) < abs(ans - target))
                    ans = sum;

                if (sum > target)
                    r--;
                else if (sum < target)
                    l++;
                else
                    return sum;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = sol.threeSumClosest(nums, target);

    cout << "Closest Sum: " << result << endl;

    return 0;
}
