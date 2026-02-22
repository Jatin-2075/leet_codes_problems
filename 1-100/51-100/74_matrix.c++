#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0;
        int high = ( matrix[0].size() * matrix.size() ) - 1;
        while(low <= high){
            int mid = ( low + high ) / 2;
            int m = mid / matrix[0].size();
            int n = mid % matrix[0].size();
            if(matrix[m][n] > target) high = mid - 1;
            else if(matrix[m][n] < target) low = mid + 1;
            else  return true;
        }
        return false;
    }
};

int main(){
    vector<vector<int>> nums = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k = 32;

    
}