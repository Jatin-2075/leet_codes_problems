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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return 0;

        vector<int> nums;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            nums.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        sort(nums.begin(), nums.end());

        int ans = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            ans = min(ans, nums[i] - nums[i - 1]);
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
         << obj.getMinimumDifference(root) << endl;

    return 0;
}
