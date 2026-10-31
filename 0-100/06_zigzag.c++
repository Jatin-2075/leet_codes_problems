#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size()) {
            return s;
        }

        vector<string> rows(numRows);

        int row = 0;
        int direction = 1;

        for (char c : s) {

            rows[row] += c;

            if (row == 0) {
                direction = 1;
            }
            else if (row == numRows - 1) {
                direction = -1;
            }

            row += direction;
        }

        string answer;

        for (string r : rows) {
            answer += r;
        }

        return answer;
    }
};

int main() {

    Solution obj;

    string s;
    int numRows;

    cin >> s;
    cin >> numRows;

    cout << obj.convert(s, numRows) << endl;

    return 0;
}