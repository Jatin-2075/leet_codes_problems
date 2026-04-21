#include <iostream>
using namespace std;

int main () {
    int n;
    cin >> n;
    int dig = 0;

    while(n != 0){
        int ld = n%10;
        dig = dig * 10 + ld;
        n/=10;
    }
    cout << dig;
}