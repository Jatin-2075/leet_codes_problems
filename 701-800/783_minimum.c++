#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        if (root == nullptr) return 0;

        vector<int> values;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            values.push_back(curr->val);

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        sort(values.begin(), values.end());

        int ans = INT_MAX;

        for (int i = 1; i < values.size(); i++) {
            ans = min(ans, values[i] - values[i - 1]);
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution obj;

    cout << "Minimum Difference = "
         << obj.minDiffInBST(root) << endl;

    return 0;
}