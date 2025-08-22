#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned;

        // Remove punctuation and spaces, convert to lowercase
        for (char c : s) {
            if (!ispunct(c) && !isspace(c)) {
                cleaned.push_back(tolower(c));
            }
        }

        // Check palindrome by comparing front and back
        int left = 0, right = (int)cleaned.size() - 1;
        while (left < right) {
            if (cleaned[left] != cleaned[right]) {
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s;
    getline(cin, s);

    if (sol.isPalindrome(s)) {
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }

    return 0;
}
