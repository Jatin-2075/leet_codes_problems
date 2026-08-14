#include <bits/stdc++.h>
using namespace std;

int m, n;

void dfs(vector<vector<char>>& board, int r, int c) {
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'X') {
        return;
    }

    board[r][c] = '.';

    dfs(board, r + 1, c);
    dfs(board, r - 1, c);
    dfs(board, r, c + 1);
    dfs(board, r, c - 1);
}

int countBattleships(vector<vector<char>>& board) {
    m = board.size();
    n = board[0].size();

    int count = 0;

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {

            if (board[r][c] == 'X') {
                count++;
                dfs(board, r, c);
            }
        }
    }

    return count;
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', '.'}
    };

    cout << "Number of battleships: "
         << countBattleships(board) << endl;

    return 0;
}