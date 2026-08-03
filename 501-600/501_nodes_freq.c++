#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map<int, int> freq;
    int maxFreq = 0;

    void dfs(TreeNode* root) {
        if (!root) return;

        freq[root->val]++;
        maxFreq = max(maxFreq, freq[root->val]);

        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        vector<int> ans;

        for (auto it : freq) {
            if (it.second == maxFreq)
                ans.push_back(it.first);
        }

        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(2);

    Solution obj;
    vector<int> ans = obj.findMode(root);

    for (int x : ans)
        cout << x << " ";

    return 0;
}