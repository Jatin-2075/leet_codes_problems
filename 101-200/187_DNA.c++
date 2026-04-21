#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set <string> repeated;
        
        set <string> seen;
        string sub = s.substr(0,10);
        seen.insert(sub);

        for(int n = 10; n < s.size(); ++n){
            sub.erase(0,1);
            sub.push_back(s[n]);

            if(seen.find(sub) != seen.end()){
                repeated.insert(sub);
            }
            else{
                seen.insert(sub);
            }
        }
        vector <string> ans;
        ans.assign(repeated.begin(), repeated.end());
        return ans;
    }
};

int main(){
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    Solution sol;

    vector<string> ans = sol.findRepeatedDnaSequences(s);
    for(auto it : ans){
        cout << it << "\n";
    }
}