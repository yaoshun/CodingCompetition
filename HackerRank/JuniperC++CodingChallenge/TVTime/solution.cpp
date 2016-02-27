#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<bool>> comm(1001, vector<bool>(60, false));
vector<vector<int>> dp(1001, vector<int>(60, INT_MIN));

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        while (t--) {
            int st, ed;
            cin >> st >> ed;
            for (int j = st; j < ed; j++) {
                // means there is a commercial between j and j + 1 on i.
                comm[i][j] = true;
            }
        }
    }
    
    dp[1][0] = 0;
    
    for (int j = 1; j <= 60; j++) {
        for (int i = 1; i <= n; i++) {
            // Three cases. 
            // shift from i - 1.
            // shift from i + 1.
            // stays on i.
            if (comm[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                dp[i][j] = dp[i][j - 1] + 1;
            }
            int small = (i - 1 == 0 ? n : i - 1);
            int large = (i == n ? 1 : i + 1);
            dp[i][j] = max(dp[small][j - 1], dp[i][j]);
            dp[i][j] = max(dp[large][j - 1], dp[i][j]);
        }
    }
    
    int res = dp[1][60];
    for (int i = 2; i <= n; i++) {
        res = max(res, dp[i][60]);
    }
    cout << res << endl;
    
    return 0;
}

