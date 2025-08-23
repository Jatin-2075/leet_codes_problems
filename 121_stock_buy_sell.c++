#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price); 
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};

int main(){
    vector<int> prices = {2,1,2,1,0,1,2};
    Solution s;
    cout << s.maxProfit(prices);
}