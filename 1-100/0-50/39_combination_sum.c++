#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int start, vector<int> &candidates, int target)
    {
        if (target == 0)
        {
            ans.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);
            dfs(i + 1, candidates, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(0, candidates, target);
        return ans;
    }
};

int main()
{
    Solution obj;

    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> res = obj.combinationSum(candidates, target);

    for (auto &v : res)
    {
        for (int x : v)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
