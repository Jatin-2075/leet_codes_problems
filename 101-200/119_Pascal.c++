#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                row[j] = row[j] + row[j - 1];
            }
        }

        return row;
    }
};

int main() {
    int rowIndex;
    cin >> rowIndex;

    Solution s;

    vector<int> ans = s.getRow(rowIndex);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}