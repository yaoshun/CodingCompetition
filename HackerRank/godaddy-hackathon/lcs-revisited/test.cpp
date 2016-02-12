#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<vector<int>> arr(3, vector<int>(N, 0));
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < N; k++) {
                cin >> arr[j][k];
            }
        }
        
        int res = 0;
        
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));
        for (int l = 1; l <= N; l++) {
            for (int m = 1; m <= N; m++) {
                for (int k = 1; k <= N; k++) {
                    dp[l][m][k] = max(dp[l - 1][m][k], max(dp[l][m - 1][k], dp[l][m][k - 1]));
                    if (arr[0][l] == arr[1][m] && arr[0][l] == arr[2][k]) {
                        dp[l][m][k] = max(dp[l][m][k], dp[l - 1][m - 1][k - 1] + 1);
                    }
                }
            }
        }
        
        cout << dp[N][N][N] << "\n";
    }
    return 0;
}
