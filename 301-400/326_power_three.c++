#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 1) return false;
        while(n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    Solution sol;
    if(sol.isPowerOfThree(num)) {
        cout << num << " is a power of 3." << endl;
    } else {
        cout << num << " is NOT a power of 3." << endl;
    }

    return 0;
}
