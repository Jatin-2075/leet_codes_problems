#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        for(int n = 0; n < strs[0].size(); ++n){
            char c = strs[0][n];
            for(int j = 0; j < strs.size(); ++j){
                if(strs[j].size() <= n || strs[j][n] != c){
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};

int main(){
    int n;
    cin >> n;

    vector<string> strs(n);
    for(int i = 0; i < n; i++){
        cin >> strs[i];
    }

    Solution obj;
    cout << obj.longestCommonPrefix(strs);
    return 0;
}