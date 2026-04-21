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
    int summaker(TreeNode* root, int low, int high){
        if(root == NULL) return 0;

        int sum = 0;

        if(low <= root->val && root->val <= high){
            sum += root->val;
        }

        if(root->val > low){
            sum += summaker(root->left, low, high);
        }

        if(root->val < high){
            sum += summaker(root->right, low, high);
        }

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return summaker(root, low, high);
    }
};

int main() {
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    Solution obj;
    cout << obj.rangeSumBST(root, 7, 15);

    return 0;
}