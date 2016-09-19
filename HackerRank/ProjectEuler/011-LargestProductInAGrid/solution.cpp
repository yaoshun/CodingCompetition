#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<vector<int>> grid(20, vector<int>(20, 0));
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> grid[i][j];
        }
    }
    
    // only go right and down, and right down diagnal.
    int res = 0;
    
    // going right
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j + 3 < 20; j++) {
            res = max(res, grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3]);
        }
    }
    
    // going down
    for (int i = 0; i + 3 < 20; i++) {
        for (int j = 0; j < 20; j++) {
            res = max(res, grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j]);
        }
    }
    
    // going right down diagonally.
    for (int i = 0; i + 3 < 20; i++) {
        for (int j = 0; j + 3 < 20; j++) {
            res = max(res, grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3]);
        }
    }
    
    // going left down diagonally.
    for (int i = 19; i - 3 >= 0; i--) {
        for (int j = 0; j + 3 < 20; j++) {
            res = max(res, grid[i][j] * grid[i - 1][j + 1] * grid[i - 2][j + 2] * grid[i - 3][j + 3]);
        }
    }
    
    cout << res << endl;
    
    return 0;
}

