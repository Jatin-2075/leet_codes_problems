#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> ans;

        while(left < right){
            int current = numbers[left] + numbers[right];

            if(current == target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
            if(current < target) left++;
            else right--;
        }
        return ans;
    }
};

int main(){
    int target = 9;
    vector<int> numbers = {2,7,15,24};

    Solution s;
    vector <int> ans = s.twoSum(numbers, target);

    for(auto it : ans){
        cout << it;
        cout << ",";
    }
}