#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long final_ans = 0;
    int temp = n;
    int digits = 0;

    while(temp > 0){
        temp /= 10;
        digits++;
    }

    temp = n;
    while(temp > 0){
        int last_digit = temp % 10;
        final_ans += pow(last_digit, digits);
        temp /= 10;
    }

    if(n == final_ans){
        cout << "yes " << n << " is an Armstrong number\n";
    } else {
        cout << "no " << n << " is not an Armstrong number\n";
    }
}
