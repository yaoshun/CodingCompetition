#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

// That's why they preallocate the space to reduce time.

#define MAX 1000
int dp[MAX];
int prv[MAX];
int st[MAX];
int ed[MAX];

using namespace std;

int main(){
    // 3D DP to solve the problem.
    // Let's reoganize the problem.
    // at the end of turn x, one robot must be at ed[x], therefore we only need one array to represent all the current information cost[i] mean one robot at i, one robot at ed[x - 1].
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;

        int res = 0;

        for (int i = 0; i < N; i++) {
            cin >> st[i] >> ed[i];
            st[i]--;
            ed[i]--;
            res += abs(ed[i] - st[i]);
        }

        // Return the results in this case.
        // Make sure N>=2
        if (N == 1) {
            cout << res << endl;
            continue;
        }

        for (int i = 0; i < M; i++) {
            dp[i] = min(abs(i - st[N - 1]), abs(ed[N - 2] - st[N - 1]));
        }

        for (int k = N - 2; k >= 1; k--) {
            for (int i = 0; i < M; i++) {
                prv[i] = dp[i];
            }

            for (int i = 0; i < M; i++) {
                dp[i] = min(abs(i - st[k]) + prv[ed[k - 1]], abs(ed[k - 1] - st[k]) + prv[i]);
            }
        }

        // Last round.
        // The first one did not have a previous location fixiation.
        int mincost = dp[0];
        for (int i = 1; i < M; i++) {
            mincost = min(dp[i], mincost);
        }

        cout << (res + mincost) << endl;
    }
}

