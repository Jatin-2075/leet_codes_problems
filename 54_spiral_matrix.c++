#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        if(matrix.empty()) return res;

        int top = 0, bottom = matrix.size()-1;
        int left = 0, right = matrix[0].size()-1;

        while(top <= bottom && left <= right){

            // right to left
            for(int n = left; n <= right; ++n){
                res.push_back(matrix[top][n]);
            }
            top++ ;

            for(int n = top; n <= bottom; ++n){
                res.push_back(matrix[n][right]);
            }
            right--;

            if(top <= bottom){
                for(int n = right; n >= left; --n){
                    res.push_back(matrix[bottom][n]);
                }
                bottom--;
            }
            if(right >= left){
                for(int n = bottom; n >= top; --n){
                    res.push_back(matrix[n][left]);
                }
                ++left;
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    Solution s;
    vector<int> result = s.spiralOrder(matrix);

    for(int x : result){
        cout << x << " ";
    }
    cout << "\n";
}
