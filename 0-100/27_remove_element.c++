#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int n = 0; n < nums.size(); ++n){
            if(nums[n] != val){
                nums[k] = nums[n];
                k++;
            }
        }
        return k;
    }
};

int main() {
    int n, val;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    cin >> val;

    Solution obj;
    int k = obj.removeElement(nums, val);

    cout << k << endl;
    for(int i = 0; i < k; i++){
        cout << nums[i] << " ";
    }

    return 0;
}
