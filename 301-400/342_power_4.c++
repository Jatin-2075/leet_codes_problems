#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        
        while(n % 4 == 0) {
            n /= 4;
        }
        
        return n == 1;     
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    Solution sol;
    if(sol.isPowerOfFour(num)) {
        cout << num << " is a power of 4." << endl;
    } else {
        cout << num << " is NOT a power of 4." << endl;
    }

    return 0;
}
