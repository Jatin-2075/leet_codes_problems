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
    bool check(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return check(root->left, minVal, root->val) &&
               check(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(8);

    Solution obj;
    if (obj.isValidBST(root))
        cout << "Valid BST";
    else
        cout << "Invalid BST";
}