#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int n = 0; n < matrix.size(); ++n){
            for(int j = n+1; j < matrix[0].size(); ++j){
                swap(matrix[n][j], matrix[j][n]);
            }
        }
        for(int n = 0; n < matrix.size(); ++n){
            reverse(matrix[n].begin(), matrix[n].end());
        }
    }
};


int main() {
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    Solution s;
    s.rotate(matrix);

    for(int n = 0; n < matrix.size(); ++n){
        for(int j = 0; j < matrix[0].size(); ++j){
            cout << matrix[n][j] << " , ";
        }
        cout << "\n";
    }
}