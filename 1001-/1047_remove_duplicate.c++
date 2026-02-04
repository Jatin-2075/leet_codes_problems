#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string st = "";

        for(char c : s){
            if(!st.empty() && st.back() == c)
                st.pop_back();
            else
                st.push_back(c);
        }

        return st;
    }
};

int main(){
    string s;
    cin >> s;

    Solution sol;
    cout << sol.removeDuplicates(s);
    return 0;
}
