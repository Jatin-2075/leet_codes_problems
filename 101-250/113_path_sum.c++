#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root, int target, vector<int>& path, vector<vector<int>>& ans) {
        if (!root) return;

        path.push_back(root->val);
        target -= root->val;

        if (!root->left && !root->right && target == 0) {
            ans.push_back(path);
        }

        dfs(root->left, target, path, ans);
        dfs(root->right, target, path, ans);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, targetSum, path, ans);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    Solution obj;
    vector<vector<int>> res = obj.pathSum(root, 22);

    for (auto& path : res) {
        for (int x : path) cout << x << " ";
        cout << endl;
    }
}