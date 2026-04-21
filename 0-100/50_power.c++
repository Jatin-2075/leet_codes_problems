#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n){
    long long N = n;
    if(n < 0){
       x = 1 / x;
       N = -N;
    }
    double ans = 1;
    while(N > 0){
        if(N % 2) ans *= x;
        x *= x;
        N /= 2;
    }
    return ans;
}

int main(){
    double x;
    int n;
    cin >> x >> n;

    cout << myPow(x, n);
}
