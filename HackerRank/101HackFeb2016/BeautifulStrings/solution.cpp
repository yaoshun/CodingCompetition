#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Use dynamic programming, dp[cnt][len] represents the number of ways
// to delete cnt chars from the prefix of length len.
#define MAX 1000001
long long dp[3][MAX] = {0};
int p[MAX] = {0};
char c[MAX];

int main() {
    string s;
    cin >> s;

    // Use idx to count the number of continuous groups.
    // Which is the main component of the same string.
    int idx = 1;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i] == s[i + 1]) {
            p[idx]++;
        } else {
            // Count the current s[i] in.
            c[idx] = s[i];
            p[idx]++;
            // Increase the index to next block.
            idx++;
        }
    }

    // n now is the number of continous groups.
    n = idx - 1;

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        // This indicate the way not delete the last group.
        dp[0][i + 1] += dp[0][i];
        dp[1][i + 1] += dp[1][i];
        dp[2][i + 1] += dp[2][i];
        if (p[i + 1] >= 2) {
            // Delete two chars from the last group.
            dp[2][i + 1] += dp[0][i];
        }
        if (p[i + 1] >= 1) {
            // block + single char + same block as previous one.
            // the deletion of the middle single char and chars from both 
            // blocks are the same.
            if (i + 2 <= n && p[i + 1] == 1 && c[i] == c[i + 2]) {
                dp[2][i + 2] -= 1;
            }

            // delete one from the last block.
            // in all scenarios.
            dp[1][i + 1] += dp[0][i];
            dp[2][i + 1] += dp[1][i];
        }
    }

    cout << dp[2][n] << endl;

    return 0;
}

