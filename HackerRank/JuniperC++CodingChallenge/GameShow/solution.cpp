#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<pair<int, int>> arr;

vector<vector<bool>> visited(1<<16, vector<bool>(17, false));
vector<vector<double>> dp(1<<16, vector<double>(17, 0));

double solve(int mask, int tot, int w) {
    if (w < 0)
        return 0.0;

    if (tot == 0)
        return 1.0;

    if (mask == 0)
        return 0.0;

    if (visited[mask][tot]) {
        return dp[mask][tot];
    }
    visited[mask][tot] = true;

    // The result is purchase order dependent.
    // This is to check the first step.
    double &res = dp[mask][tot];
    res = 0.0;
    for (int i = 0; i < n; i++) {
        // means it is still available;
        if ((mask >> i) & 1) {
            double x = solve(mask ^ (1 << i), tot - 1, w - arr[i].first) * arr[i].second / 100.0 + solve(mask ^ (1 << i), tot, w - arr[i].first) * (1 - arr[i].second / 100.0);
            res = max(res, x);
        }
    }
    return res;
}

int main() {
    int w, tot;
    cin >> n >> tot >> w;

    double ans = 0.0;
    for (int i = 0; i < n; i++) {
        int price, prob;
        cin >> price >> prob;
        arr.push_back({price, prob});
    }

    ans = solve((1<<n)-1, tot, w);
    cout << ans << endl;
}
