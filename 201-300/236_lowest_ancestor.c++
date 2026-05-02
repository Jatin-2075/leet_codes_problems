#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }    
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL) return NULL;

        if (root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left != NULL && right != NULL) return root;

        if (left != NULL) return left;

        return right;
    }
};

int main(){

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    Solution obj;

    TreeNode* p = root->left->left;  // 6
    TreeNode* q = root->left->right; // 2

    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);

    cout << "LCA: " << ans->val << endl;

    return 0;
}