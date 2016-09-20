#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void backtrack(vector<int>& res, vector<vector<int>>& dp, int* a, int* b, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    } else if (a[i - 1] == b[j - 1]) {
        backtrack(res, dp, a, b, i - 1, j - 1);
        res.push_back(a[i - 1]);
        return;
    } else {
        if (dp[i][j - 1] > dp[i - 1][j]) {
            backtrack(res, dp, a, b, i, j - 1);
            return;
        } else {
            backtrack(res, dp, a, b, i - 1, j);
            return;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int a[105];
    int b[105];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            }
        }
    }

    vector<int> res;
    backtrack(res, dp, a, b, n, m);

    for (int i = 0; i < res.size(); i++) {
        if (i == 0) cout << res[i];
        else cout << " " << res[i];
    }
    cout << endl;

    return 0;
}
