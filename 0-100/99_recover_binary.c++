#include <iostream>
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
private:
    TreeNode *first = nullptr;
    TreeNode *second = nullptr;
    TreeNode *prev = nullptr;

    void inorder(TreeNode *root) {
        if (root == nullptr)
            return;

        inorder(root->left);

        if (prev != nullptr && prev->val > root->val) {
            if (first == nullptr)
                first = prev;

            second = root;
        }

        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root) {
        inorder(root);

        if (first && second)
            swap(first->val, second->val);
    }
};

void inorderPrint(TreeNode *root) {
    if (!root)
        return;

    inorderPrint(root->left);
    cout << root->val << " ";
    inorderPrint(root->right);
}

int main() {

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout << "Before Recovery (Inorder): ";
    inorderPrint(root);
    cout << endl;

    Solution obj;
    obj.recoverTree(root);

    cout << "After Recovery (Inorder): ";
    inorderPrint(root);
    cout << endl;

    return 0;
}