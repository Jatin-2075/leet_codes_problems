#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0, ans = 0;
        int maxleft = 0, maxright = 0;
        vector <int> left, right;

        for(int i = 0; i < height.size(); i++){
            if(maxleft < height[i]){
                maxleft = height[i];
            }
            left.push_back(maxleft);
        }

        for(int i = height.size() - 1; i >= 0; i--){
            if(maxright < height[i]){
                maxright = height[i];
            }
            right.push_back(maxright);
        }

        reverse(right.begin(), right.end());

        while(i < height.size()){
            int idk = min(left[i], right[i]);

            ans += idk - height[i];
            i++;
        }

        return ans;
    }
};

int main(){
    vector <int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;

    cout << s.trap(height);
}