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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root1, root2});

        while (!q.empty()) {
            auto [node1, node2] = q.front();
            q.pop();

            node1->val += node2->val;

            if (node1->left && node2->left) {
                q.push({node1->left, node2->left});
            } else if (!node1->left) {
                node1->left = node2->left;
            }

            if (node1->right && node2->right) {
                q.push({node1->right, node2->right});
            } else if (!node1->right) {
                node1->right = node2->right;
            }
        }

        return root1;
    }
};

void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }

    cout << endl;
}


int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(3);
    root1->right = new TreeNode(2);
    root1->left->left = new TreeNode(5);

    TreeNode* root2 = new TreeNode(2);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(3);
    root2->left->right = new TreeNode(4);
    root2->right->right = new TreeNode(7);

    Solution obj;
    TreeNode* merged = obj.mergeTrees(root1, root2);

    cout << "Level Order of Merged Tree: ";
    levelOrder(merged);

    return 0;
}