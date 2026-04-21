#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int largestprice = 0;
        int smallestprice = INT_MAX;
        for(int n = 1; n < prices.size(); ++n){
            if(prices[n] > prices[n-1]){
                maxprofit += prices[n] - prices[n-1];
            }
        }
        return maxprofit;
    }
};

int main(){
    vector<int> prices = {2,1,2,1,10,1,2};
    Solution s;
    cout << s.maxProfit(prices);
} 