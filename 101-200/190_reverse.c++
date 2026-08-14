#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }

        return ans;
    }
};

int main() {
    Solution obj;

    uint32_t n = 43261596;

    uint32_t ans = obj.reverseBits(n);

    cout << ans << endl;

    return 0;
}