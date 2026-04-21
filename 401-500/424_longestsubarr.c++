#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0, ans = 0, maxfreq = 0;
        unordered_map<char, int> freq;
        while(right < s.size()){
            freq[s[right]]++;
            maxfreq = max(maxfreq, freq[s[right]]);
            right++;

            while(((right - left) - maxfreq) > k){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans, right - left);
        }
        
        return ans;
    }
};

int main(){
    string s;
    int k;
}