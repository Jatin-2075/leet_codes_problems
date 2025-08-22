#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
       for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else {
                if(st.empty() ) return false;

            if((c == ')' && st.top() == '(') ||
               (c == '}' && st.top() == '{') ||
               (c == ']' && st.top() == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
    };
};
    



int main() {
    Solution obj;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    bool ans = obj.isValid(s);

    if(ans) cout << "Valid\n";
    else cout << "Invalid\n";

    return 0;
}