#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {
    }
    
    int ping(int t) {

        q.push(t);

        while(!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

int main() {

    RecentCounter rc;

    int n;
    cout << "How many pings: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;

        cout << "Requests in last 3000 ms: "
             << rc.ping(t) << endl;
    }

    return 0;
}
