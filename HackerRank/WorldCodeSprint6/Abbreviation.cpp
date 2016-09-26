#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
        while (q--) {
        string a, b;
        cin >> a >> b;
        int m = a.size();
        int n = b.size();
        // dp[i][j] represents a[0...i-1] is convertible to b[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i++) {
            if (a[i - 1] >= 'a' && a[i - 1] <= 'z') {
                dp[i][0] = true;
            } else {
                break;
            }
        }
        // dp[0][n] is false; no need to change.
        // dp[i][0] is true until the first upper case.
    
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i - 1] >= 'a' && a[i - 1] <= 'z') {
                    if (dp[i - 1][j]) {
                        // Delete it.
                        dp[i][j] = true;
                    } else if (a[i - 1] + 'A' - 'a' == b[j - 1]){
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                } else {
                    // must be used a[i - 1]
                    if (a[i - 1] != b[j - 1]) {
                        dp[i][j] = false;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        cout << (dp[m][n]?"YES":"NO") << endl;
    }
    return 0;
}
