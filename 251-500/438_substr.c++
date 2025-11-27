#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {  

        vector<int> ans;

        int k = p.size();
        if(s.size() < k) return ans;

        vector <int> sfreq(26,0), pfreq(26,0);

        for(int n = 0; n < k; n++){
            sfreq[s[n] - 'a']++;
            pfreq[p[n] - 'a']++;
        }

        if(sfreq == pfreq) ans.push_back(0);

        for(int n = k; n < s.size(); n++){
            sfreq[s[n - k] - 'a']--;
            sfreq[s[n] - 'a']++;

            if(sfreq == pfreq) ans.push_back(n - k + 1);
        }
        

        return ans;
    }
};

int main() {
    string s = "abab", p = "ab";
    Solution sol;

    vector<int> ans = sol.findAnagrams(s,p); 

    for(int i : ans) cout << i << " ";
}