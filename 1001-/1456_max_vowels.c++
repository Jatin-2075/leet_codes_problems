#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        int occ = 0, ans = 0;

        auto isVowel = [&](char c){
            return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
        };

        for(int i = 0; i < k; i++){
            if(isVowel(s[i])) occ++;
        }
        ans = occ;

        for(int i = k; i < s.size(); i++){
            if(isVowel(s[i])) occ++;
            if(isVowel(s[i-k])) occ--;

            ans = max(ans, occ);
        }

        return ans;
    }
};


int main(){
    string s = "abciiidef";
    int k = 3;

    Solution sol;
    cout << sol.maxVowels(s,k);
}