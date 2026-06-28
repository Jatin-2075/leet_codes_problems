#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<vector<char>>& board, string& word, int i, int j, int k) {

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;

        if (board[i][j] != word[k])
            return false;

        if (k == word.size() - 1)
            return true;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found =
            search(board, word, i + 1, j, k + 1) ||
            search(board, word, i - 1, j, k + 1) ||
            search(board, word, i, j + 1, k + 1) ||
            search(board, word, i, j - 1, k + 1);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {

                if (search(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    Solution obj;

    if (obj.exist(board, word))
        cout << "Word Found\n";
    else
        cout << "Word Not Found\n";

    return 0;
}

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };

    string word = "ABCCED";

    Solution obj;

    if (obj.exist(board, word))
        cout << "Word Found\n";
    else
        cout << "Word Not Found\n";

    return 0;
}