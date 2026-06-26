#include <bits/stdc++.h>
using namespace std;

int pick = 6;

int guess(int num) {
    if (num > pick)
        return -1;
    if (num < pick)
        return 1;
    return 0;
}

class Solution {
public:
    int guessNumber(int n) {
        int low = 1;
        int high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int res = guess(mid);

            if (res == 0)
                return mid;
            else if (res == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};

int main() {
    int n = 10;

    Solution s;
    cout << "Picked Number: " << s.guessNumber(n);

    return 0;
}