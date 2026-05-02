#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
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
    void dfs(TreeNode* root, int level, vector<int>& ans){
        if(root == NULL) return;

        if(level == ans.size()){
            ans.push_back(root->val);
        }

        dfs(root->right, level + 1, ans);
        dfs(root->left, level + 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

int main(){
    // simple test tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution obj;
    vector<int> ans = obj.rightSideView(root);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}