#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (citations[mid] >= n - mid) {
                ans = n - mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> citations(n);

    for (int i = 0; i < n; i++) {
        cin >> citations[i];
    }

    Solution obj;
    cout << obj.hIndex(citations) << endl;

    return 0;
}