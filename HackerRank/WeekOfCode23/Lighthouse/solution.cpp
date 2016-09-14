#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                int cur = min(abs(n - 1 - j), j);
                cur = min(cur, i);
                cur = min(cur, abs(n - 1 - i));
                for (int k = 0; k < n; k++) {
                    for (int l = 0; l < n; l++) {
                        if (grid[k][l] == '*') {
                            while (cur * cur >= (k - i) * (k - i) + (l - j) * (l - j)) {
                                cur--;
                            }
                        }
                    }
                }
                res = max(cur, res);
            }
        }
    }
    cout << res << endl;
    return 0;
}

