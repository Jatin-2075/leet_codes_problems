#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int formula(int n)
    {
        return n * (n + 1) / 2;
    }
    int arrangeCoins(int n)
    {
        int low = 0, high = n;
        int ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (formula(mid) <= n)
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{
    int n = 5;
    Solution s;
    cout << s.arrangeCoins(n);
}