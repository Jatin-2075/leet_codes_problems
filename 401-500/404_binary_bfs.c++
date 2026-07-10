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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;

        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                if (node->left->left == nullptr &&
                    node->left->right == nullptr) {
                    sum += node->left->val;
                } else {
                    q.push(node->left);
                }
            }

            if (node->right) {
                if (node->right->left != nullptr ||
                    node->right->right != nullptr) {
                    q.push(node->right);
                }
            }
        }

        return sum;
    }
};

int main() {
   TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Sum of Left Leaves = "
         << obj.sumOfLeftLeaves(root) << endl;

    return 0;
}
