#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> makerow(int n) {
        vector<int> temp(n + 1, 1);
        for (int k = 1; k < n; k++) {
            temp[k] = (long long)temp[k - 1] * (n - k + 1) / k;
        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalans;
        for (int n = 0; n < numRows; ++n) {
            finalans.push_back(makerow(n));
        }
        return finalans;
    }
};

int main() {
    Solution sol;
    int numRows = 5;
    vector<vector<int>> res = sol.generate(numRows);

    for (auto &row : res) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
