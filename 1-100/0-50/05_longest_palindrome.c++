#include <iostream>
#include <string>
using namespace std;

string expand(string s, int l, int r) {
    while (l >= 0 && r < s.length() && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
    string ans = "";

    for (int i = 0; i < s.length(); i++) {

        string odd = expand(s, i, i);
        if (odd.length() > ans.length())
            ans = odd;

        string even = expand(s, i, i + 1);
        if (even.length() > ans.length())
            ans = even;
    }

    return ans;
}

int main() {

    string s;
    cout << "Enter string: ";
    cin >> s;

    cout << "Longest Palindromic Substring: " << longestPalindrome(s);

    return 0;
}