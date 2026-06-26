#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while (columnNumber > 0) {
            columnNumber--;

            char ch = 'A' + (columnNumber % 26);
            ans += ch;

            columnNumber /= 26;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution s;

    int columnNumber;
    cout << "Enter column number: ";
    cin >> columnNumber;

    cout << "Excel Column Title: " << s.convertToTitle(columnNumber) << endl;

    return 0;
}