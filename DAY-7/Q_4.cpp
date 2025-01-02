/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/

/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.*/

#include <iostream>
#include <queue>
using namespace std;

int orangesRotting(int** grid, int m, int n) {
    queue<pair<int, int>> q;
    int fresh = 0;
    int minutes = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty() && fresh > 0) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            pair<int, int> current = q.front();  // No structured bindings
            q.pop();
            int x = current.first;
            int y = current.second;

            for (int d = 0; d < 4; d++) {
                int nx = x + directions[d][0];
                int ny = y + directions[d][1];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                }
            }
        }
        minutes++;
    }

    return fresh == 0 ? minutes : -1;
}

int main() {
    int m, n;
    cin >> m >> n;

    int** grid = new int*[m];
    for (int i = 0; i < m; i++) {
        grid[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << orangesRotting(grid, m, n) << endl;

    for (int i = 0; i < m; i++) {
        delete[] grid[i];
    }
    delete[] grid;

    return 0;
}
