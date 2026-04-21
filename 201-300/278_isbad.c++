#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n, ans = n;

        while(left <= right){
            long long mid = left + (right - left) / 2;

            // if(isBadVersion(mid)){
            //     ans = mid;
            //     right = mid - 1;
            // }
            // else left = mid + 1;
        }
        return ans;
    }
};

int main(){
    int n = 5;
    Solution s;

    cout << s.firstBadVersion(n);
}