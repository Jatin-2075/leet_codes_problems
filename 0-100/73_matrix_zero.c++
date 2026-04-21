#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector <int> zerorow;
        vector <int> zerocol;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if(matrix[i][j] == 0) {
                    zerorow.push_back(i);
                    zerocol.push_back(j);
                };
            }
        }

        for(int n = 0; n < zerocol.size(); ++n){
            int row = zerorow[n];
            int col = zerocol[n];

            for(int k = 0; k < matrix[0].size(); ++k){
                matrix[row][k] = 0;
            }
            for(int k = 0; k < matrix.size(); ++k){
                matrix[k][col] = 0;
            }
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
    s.setZeroes(matrix);

    for(int n = 0; n < matrix.size(); ++n){
        for(int j = 0; j < matrix[0].size(); ++j){
            cout << matrix[n][j] << " , ";
        }
        cout << "\n";
    }
}