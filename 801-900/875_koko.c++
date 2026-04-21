#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());

        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = INT_MAX;

        while(low <= high){
            int mid = low + (high - low) / 2;
            int count = 0;

            for(int n = 0; n < piles.size(); n++){
                count += (piles[n] + mid - 1 ) / mid;
            }

            if(count > h){
                low = mid + 1;
            }
            else{
                ans = mid;
                high  = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    vector <int> piles = {3,6,7,11};
    int k = 8;

    Solution s;
    cout << s.minEatingSpeed(piles, k);
}