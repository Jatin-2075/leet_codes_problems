#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int,int>> zeros;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0)
                    zeros.push_back({i,j});
            }
        }

        for(auto &p : zeros){
            int r = p.first, c = p.second;
            for(int i = 0; i < rows; i++) matrix[i][c] = 0;
            for(int j = 0; j < cols; j++) matrix[r][j] = 0;
        }
    }
};

int main() {
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    Solution s;
    s.setZeroes(matrix);

    for(int n = 0; n < matrix.size(); ++n){
        for(int j = 0; j < matrix[0].size(); ++j){
            cout << matrix[n][j] << " ";
        }
        cout << "\n";
    }
}
