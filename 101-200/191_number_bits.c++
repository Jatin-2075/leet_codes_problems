#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n) {
            count += (n & 1);
            n >>= 1;
        }

        return count;
    }
};

int main() {
    Solution obj;
    uint32_t n = 11;
    cout << obj.hammingWeight(n);
}