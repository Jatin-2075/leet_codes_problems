#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        if(n < 3) return 0;

        int ans = 0;

        for(int i = 0; i + 3 <= n; i++){
            char a = s[i];
            char b = s[i+1];
            char c = s[i+2];

            if(a != b && b != c && a != c){
                ans++;
            }
        }

        return ans;
    }
};


int main(){
    string s = "aababcabc";
    Solution sol;
    cout << sol.countGoodSubstrings(s);
}