#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();

        if (k == 0)
            return vector<int>(n, 0);

        vector<int> ans(n);

        if (k > 0) {

            int sum = 0;

            for (int i = 1; i <= k; i++)
                sum += code[i % n];

            for (int i = 0; i < n; i++) {

                ans[i] = sum;

                sum -= code[(i + 1) % n];
                sum += code[(i + k + 1) % n];
            }
        }
        else {

            k = -k;
            int sum = 0;

            for (int i = 1; i <= k; i++)
                sum += code[(n - i) % n];

            for (int i = 0; i < n; i++) {

                ans[i] = sum;

                sum -= code[(i - k + n) % n];
                sum += code[i];
            }
        }

        return ans;
    }
};

int main() {

    Solution obj;

    vector<int> code = {5, 7, 1, 4};
    int k = 3;

    vector<int> ans = obj.decrypt(code, k);

    for (int x : ans)
        cout << x << " ";

    return 0;
}