#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(int start, int n, int k) {
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++){
            temp.push_back(i);
            dfs(i + 1, n, k); 
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        dfs(1, n, k);
        return ans;
    }
};

int main(){
    int n = 4, k = 2;
    Solution s;
    vector<vector<int>>ans = s.combine(n ,k);
}