#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

// Analysis of the problem is more important than figuring out an algorithm
// first: each possible solution must contains a connected component which
// will eventually be a cycle (if no cycle, it is a tree and can only have n -1 edge).
// For each connected component, if the cycle length is 2, it becomes a special case that I failed to discover. The cycle length 2 connected component can form a self-standing part in the final solution.
// If the cycle length is bigger than 2, the final solution can only contaio// this single connected component cycle.
// The final results are the max of these two cases.

// The below is a improved solution from nika.

// array a for recording the neighbor.
// array v for recording the visited or not.
// array d for recording the depth of array.
int a[1005], v[1005], d[1005];

void solve() {
    int n;
    cin >> n;
    int ans = 0;

    // Since the array is 1-index based.
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    // Cycle based case.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[j] = 0;
        }
        int cur = i;
        int k = 0;
        while (true) {
            v[cur] = 1;
            cur = a[cur];
            k++;
            if (v[cur]) break;
        }

        // Here means starting from i, we
        // just formed a perfect loop.
        if (cur == i) {
            ans = max(ans, k);
        }
    }

    // 2 cycle based case. 
    for (int j = 1; j <= n; j++) {
        v[j] = d[j] = 0;
    }

    // The idea of this part, is that by cycling the DP process
    // n times, we can definitely get the right results.
    // For those have a cycle of more than 2, it will have
    // very large numbers: but it doesn't matter.
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (a[a[i]] != i) {
                d[a[i]] = max(d[a[i]], d[i] + 1);
            }
        }
    }

    int ans2 = 0;
    for (int i = 1; i <= n; i++) {
        if (!v[i] && a[a[i]] == i) {
            ans2 += 2 + d[i] + d[a[i]];
            // i and a[i] cycle should only be visited once.
            v[i] = v[a[i]] = 1;
        }
    }

    ans = max(ans, ans2);
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": ";
        solve();
    }    
    return 0;
}
