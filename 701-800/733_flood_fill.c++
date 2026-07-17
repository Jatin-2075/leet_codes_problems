#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();

    int oldColor = image[sr][sc];
    if (oldColor == color)
        return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                image[nr][nc] == oldColor) {

                image[nr][nc] = color;
                q.push({nr, nc});
            }
        }
    }

    return image;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, color;
    cin >> sr >> sc >> color;

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    cout << "Flood Filled Image:\n";
    for (auto &row : ans) {
        for (auto x : row)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}