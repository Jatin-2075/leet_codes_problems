#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int rev = 0;
        int n = x;

        while (n > 0) {
            int ld = n % 10;
            rev = (rev * 10) + ld;
            n /= 10;
        }

        return rev == x;
    }
};

int main() {
    int n;
    cin >> n;

    Solution obj;
    bool result = obj.isPalindrome(n);

    cout << (result ? "true" : "false") << endl;

    return 0;
}
