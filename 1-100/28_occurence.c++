#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int length = needle.size();
        if(haystack.size() < needle.size()) return -1;
        for ( int n = 0; n <= haystack.size() - length; ++n){
            string sub = haystack.substr(n, length);
            if(sub == needle){
                return n;
            }
        }
        return -1;
    }
};

int main() {
    string haystack = "sadbutsad", needle = "sad";
    Solution sol;
    cout << sol.strStr(haystack, needle);
}