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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            level.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        ans.push_back(level);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> result = levelOrderBottom(root);

    cout << "Bottom-up Level Order Traversal:\n";
    for (const auto& level : result) {
        for (int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}