#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        map<int, int> mpp;

        for (auto &row : matrix) {
            for (int x : row) {
                mpp[x]++;
            }
        }

        for (auto &[num, freq] : mpp) {
            if (k <= freq)
                return num;
            k -= freq;
        }

        return -1;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };

    int k = 8;

    Solution s;
    cout << s.kthSmallest(matrix, k);
}