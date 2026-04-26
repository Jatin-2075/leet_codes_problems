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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if(!root)return {};

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int count = q.size();
        vector<int> currentlevel;

        for(int i = 0; i < count; i++){
            TreeNode* node = q.front();
            q.pop();

            currentlevel.push_back(node->val);

            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        ans.push_back(currentlevel);
    }
    return ans;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    vector<vector<int>> ans = levelOrder(root);
}