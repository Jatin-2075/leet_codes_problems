#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        val = 0;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution {
public:
    void dfs(map<int, map<int, multiset<int>>>& mpp, int col, int row, TreeNode* root) {
        if (!root) return;

        mpp[col][row].insert(root->val);

        dfs(mpp, col - 1, row + 1, root->left);
        dfs(mpp, col + 1, row + 1, root->right);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> mpp;

        dfs(mpp, 0, 0, root);

        for (auto &col : mpp) {
            vector<int> temp;

            for (auto &row : col.second) {
                for (int val : row.second) {
                    temp.push_back(val);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }
};

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    vector<vector<int>> ans = obj.verticalTraversal(root);

    for (auto &col : ans) {
        for (int x : col)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}