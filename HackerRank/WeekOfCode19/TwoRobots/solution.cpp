#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// That's why they preallocate the space to reduce time.

#define MAX 1000
int dp[MAX][MAX];
int prv[MAX][MAX];
int st[MAX];
int ed[MAX];

using namespace std;

inline int getCost(int i, int j) {
    if (i < j) {
        swap(i, j);
    }
    return prv[i][j];
}

int main(){
    // 3D DP to solve the problem.
    // dp[i][j][k] represents the cost of robot position i and j
    // to solve problems k to n - 1.
    // Eventually we evaluate the minimum of 2D array dp[i][j][0].
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;

        for (int i = 0; i < N; i++) {
            cin >> st[i] >> ed[i];
            st[i]--;
            ed[i]--;
        }

        // reversely DP, reduce to 2D.
        // Utilized symmetry.
        for (int i = 0; i < M; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = min(abs(i - st[N - 1]), abs(j - st[N - 1])) + abs(ed[N - 1] - st[N - 1]);
            }
        }

        for (int k = N - 2; k >= 0; k--) {
            for (int i = 0; i < M; i++) {
                for (int j = 0; j <= i; j++) {
                    prv[i][j] = dp[i][j];
                }
            }

            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    dp[i][j] = min(abs(i - st[k]) + abs(ed[k] - st[k]) + getCost(ed[k], j),
                                      abs(j - st[k]) + abs(ed[k] - st[k]) + getCost(i, ed[k]));
                }
            }
        }

        int res = dp[0][0];
        for (int i = 0; i < M; i++) {
            for (int j = 0; j <= i; j++) {
                res = min(res, dp[i][j]);
            }
        }

        cout << res << endl;
    }
}

