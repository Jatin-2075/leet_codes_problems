#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            word = "";
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    vector<string> ans;

    void insert(TrieNode* root, string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->child[index] == nullptr) {
                curr->child[index] = new TrieNode();
            }

            curr = curr->child[index];
        }

        curr->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int i, int j,
             TrieNode* node) {

        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return;
        }

        if (board[i][j] == '#')
            return;

        char c = board[i][j];
        int index = c - 'a';

        if (node->child[index] == nullptr)
            return;

        node = node->child[index];

        if (node->word != "") {
            ans.push_back(node->word);

            node->word = "";
        }

        board[i][j] = '#';

        dfs(board, i - 1, j, node);
        dfs(board, i + 1, j, node);
        dfs(board, i, j - 1, node);
        dfs(board, i, j + 1, node);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        TrieNode* root = new TrieNode();

        for (string word : words) {
            insert(root, word);
        }

        ans.clear();
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {
        "oath",
        "pea",
        "eat",
        "rain"
    };

    vector<string> result = s.findWords(board, words);

    for (string word : result) {
        cout << word << endl;
    }

    return 0;
}