#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int ans = 0;

    void dfs(TreeNode* root, int curr) {
        if (!root) return;

        curr = curr * 10 + root->val;
        
        if (!root->left && !root->right) {
            ans += curr;
            return;
        }

        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution obj;
    cout << obj.sumNumbers(root);   // 25
}