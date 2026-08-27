#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && st.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> wordDict(n);

    for (int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    cout << boolalpha << sol.wordBreak(s, wordDict) << endl;

    return 0;
}