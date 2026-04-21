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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;

        if(root->val == val) return root;

        if(val < root->val) 
            return searchBST(root->left, val);
        else 
            return searchBST(root->right, val);
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    Solution obj;

    int target = 7;
    TreeNode* result = obj.searchBST(root, target);

    if(result)
        cout << "Found: " << result->val << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}