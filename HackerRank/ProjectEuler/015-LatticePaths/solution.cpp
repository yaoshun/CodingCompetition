nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const long long P = 1000000007;

long long dp[1001][1001];

void preprocessing() {
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= 1000; i++) {
        dp[i][0] = 1;
        for (int j = 1; j < i; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % P;
        }
        dp[i][i] = 1;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    
    preprocessing();
    
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        // This problem is essentially calculation C(n+m, m).
        // Directly calculate it will met the difficulty of modular operations.
        // multiplication is not a good one for modular operations since it invovles
        // division around the process.
        cout << dp[n + m][min(n, m)] << endl;
    }
    return 0;
}

