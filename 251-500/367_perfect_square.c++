#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long left = 0, right = num;

        while(left <= right){
            long long mid = left + (right - left) / 2;
            long long ans = mid * mid;

            if(ans > num) right = mid - 1;
            else if (ans < num) left = mid + 1;
            else return true;
        }
        return false;
    }
};

int main(){
    int num = 16;

    Solution s;
    cout << s.isPerfectSquare(num);
}