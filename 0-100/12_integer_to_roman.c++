#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        int thousand = (num / 1000) % 10;
        int hundreds = (num / 100) % 10;
        int tens = (num / 10) % 10;
        int ones = num % 10;

        if(thousand <= 3){
            for(int k = 0; k < thousand; ++k){
                res += "M";
            }
        }

        if (hundreds == 9) res += "CM";
        else if (hundreds >= 5) {
            res += "D";
            for (int i = 0; i < hundreds - 5; i++) res += "C";
        } else if (hundreds == 4) res += "CD";
        else {
            for (int i = 0; i < hundreds; i++) res += "C";
        }

        if (tens == 9) res += "XC";
        else if (tens >= 5) {
            res += "L";
            for (int i = 0; i < tens - 5; i++) res += "X";
        } else if (tens == 4) res += "XL";
        else {
            for (int i = 0; i < tens; i++) res += "X";
        }

        if (ones == 9) res += "IX";
        else if (ones >= 5) {
            res += "V";
            for (int i = 0; i < ones - 5; i++) res += "I";
        } else if (ones == 4) res += "IV";
        else {
            for (int i = 0; i < ones; i++) res += "I";
        }

        return res;
    }
};

int main() {
    Solution sol;
    int num;
    cin >> num;
    cout << sol.intToRoman(num) << endl;
    return 0;
}
