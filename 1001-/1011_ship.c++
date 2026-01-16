#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0, high = 0;

        for(int i : weights){
            high += i;
            if(low < i)low = i;
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            int days_used = 1, count = 0, index = 0;

            while(index < weights.size()){
                if(count + weights[index] <= mid){
                    count += weights[index];
                }
                else{
                    count = weights[index];
                    days_used++;
                }
                index++;
            }

            if(days_used > days){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};

int main(){

    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int days = 5;

    Solution s;
    cout << s.shipWithinDays(weights, days);
    return 0;
}