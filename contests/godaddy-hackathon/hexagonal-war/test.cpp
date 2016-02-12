#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

bool dfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int i, int j, int val) {
    visited[i][j] = true;
    if (val == 1 && j == N - 1) {
        return true;
    } else if (val == 2 && i == N - 1) {
        return true;
    }
    
    int di[] = {0, 0, -1, -1, 1, 1};
    int dj[] = {1, -1, 0, 1, -1, 0};
    for (int k = 0; k < 6; k++) {
        int newi = i + di[k];
        int newj = j + dj[k];
        if (newi >= 0 && newi < N && newj >= 0 && newj < N && board[newi][newj] == val && visited[newi][newj] == false) {
            if (dfs(board, visited, newi, newj, val)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        if ((i % 2) == 0) {
            // ROMANS
            board[x - 1][y - 1] = 1;
        } else {
            // PERSIANS
            board[x - 1][y - 1] = 2;
        }
    }
    
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    // ROMANS left to right check.
    for (int i = 0; i < N; i++) {
        if (board[i][0] == 1 && visited[i][0] == false) {
            if (dfs(board, visited, i, 0, 1)) {
                cout << "ROMANS";
                return 0;
            }
        }
    }
    
    // PERSIANS top to bottom check.
    for (int i = 0; i < N; i++) {
        if (board[0][i] == 2 && visited[0][i] == false) {
            if (dfs(board, visited, 0, i, 2)) {
                cout << "PERSIANS";
                return 0;
            }
        }
    }
    
    cout << "NEITHER";
    return 0;
}

