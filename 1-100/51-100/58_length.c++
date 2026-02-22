#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = 0 ;
        for(int n = s.size()-1; n >= 0; n--){
            if(s[n] != ' '){
                k += 1;
            }
            else if(k > 0 && s[n] == ' ' ){
                return k;
            }
        }
        return k;
    }
};

int main () {

    string s = "Hello World";
    Solution sol;
    cout << sol.lengthOfLastWord(s);

}