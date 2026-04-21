#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        vector<string> roman_data = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> integer_data =  {1000, 900, 500, 400, 100, 90,  50,  40,  10,   9,   5,   4,   1};

        for (int i = 0; i < roman_data.size(); ++i) {
            while (s.substr(0, roman_data[i].length()) == roman_data[i]) {
                result += integer_data[i];
                s.erase(0, roman_data[i].length());
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s;
    cin >> s;
    cout << sol.romanToInt(s);
}
