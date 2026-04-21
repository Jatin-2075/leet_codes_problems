#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void solve(int index, string curr, string digits, vector<string>& map){
        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }

        string letters = map[digits[index] - '0'];

        for(char c : letters){
            solve(index + 1, curr + c, digits, map);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};

        vector<string> map = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(0, "", digits, map);
        return ans;
    }
};

int main(){
    string digits;
    cout << "Enter digits: ";
    cin >> digits;

    Solution obj;
    vector<string> result = obj.letterCombinations(digits);

    cout << "Combinations:\n";
    for(string s : result){
        cout << s << endl;
    }

    return 0;
}