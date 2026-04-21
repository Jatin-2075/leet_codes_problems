#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1, left = 0, ans = 0, current = 0;
        while(left < right){
            ans = max((min(height[left], height[right]) * (right - left)), ans );
            if(height[left] < height[right])left++;
            else right--;
        }

        return ans;
    }
};

int main(){
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    Solution s;
    cout << s.maxArea(height);
}