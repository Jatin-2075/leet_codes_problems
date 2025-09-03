#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;

        int i = 0;
        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main(){
    vector<int> nums = {1,1,2,2,3,3,4};

    Solution s;
    int k = s.removeDuplicates(nums);

    cout << "Unique count: " << k << endl;
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < k; i++){
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
