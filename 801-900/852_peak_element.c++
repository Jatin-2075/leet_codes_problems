#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        long long left = 0, right = arr.size() - 2;

        while(left <= right){
            long long mid = left + (right - left) / 2;

            if(arr[mid] > arr[mid + 1]) right = mid - 1;
            else if(arr[mid] < arr[mid + 1]) left = mid + 1;
        }
        return left;
    }
};

int main(){
    vector<int> arr = {0,1,3,10,4,0};

    Solution s;
    cout << s.peakIndexInMountainArray(arr);
}