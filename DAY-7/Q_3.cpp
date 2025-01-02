/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.*/

#include <iostream>
using namespace std;

bool dfs(char** board, int m, int n, string& word, int i, int j, int index) {
    if (index == word.size()) return true;
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) return false;

    char temp = board[i][j];
    board[i][j] = '#';
    bool found = dfs(board, m, n, word, i + 1, j, index + 1) ||
                 dfs(board, m, n, word, i - 1, j, index + 1) ||
                 dfs(board, m, n, word, i, j + 1, index + 1) ||
                 dfs(board, m, n, word, i, j - 1, index + 1);
    board[i][j] = temp;
    return found;
}

bool exist(char** board, int m, int n, string word) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dfs(board, m, n, word, i, j, 0)) return true;
        }
    }
    return false;
}

int main() {
    int m, n;
    cin >> m >> n;

    char** board = new char*[m];
    for (int i = 0; i < m; i++) {
        board[i] = new char[n];
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    if (exist(board, m, n, word)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    for (int i = 0; i < m; i++) {
        delete[] board[i];
    }
    delete[] board;

    return 0;
}
