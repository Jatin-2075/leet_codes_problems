#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            set<char> seen;

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                if (seen.count(board[i][j]))
                    return false;

                seen.insert(board[i][j]);
            }
        }

        for (int j = 0; j < 9; j++) {
            set<char> seen;

            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;

                if (seen.count(board[i][j]))
                    return false;

                seen.insert(board[i][j]);
            }
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {

                set<char> seen;

                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {

                        if (board[i][j] == '.') continue;

                        if (seen.count(board[i][j]))
                            return false;

                        seen.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution s;
    cout << s.isValidSudoku(board) << "\n"; // 1 = valid, 0 = invalid
}