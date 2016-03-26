#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

const int MAX = 100002;
const ll P = 1000000007;

// m <= 5.
// 7 is more than enough.
// it is actually a 3d array d[n][m][m]
struct DP {
    ll a[7][7];
} d[MAX], T, T0;
int n, m;
vector<int> v[MAX];

// Let's make dp[x][y][z] on rooted tree (z <= y). Number of different variants in subtree x, to repair y roads and z of them are starting in x.
// Update parent(p) from child(c), dp[p][y][z] from dp[c][yy][zz].
// There are 3 variants:
// 1) not repairing edge (p,c).
// 2) repairing edge (p, c) and stop in p.
// 3) repairing edge (p, c) and continue repairing in the other child of p.

// go function is a good way to traverse the tree.
// since once we fixed a root, each node only has one parent.
// Here we denoted it as "fr".
void go(int x, int fr) {
    // Ending contition for leaf nodes.
    // Only one possibility of repairing zero roads. 
    d[x].a[0][0] = 1;

    // Condition there is some neighbors.
    for (int i = 0; i < v[x].size(); i++) {
        int to = v[x][i];
        if (to == fr) continue;
        go(to, x);
        // T represents the possibility of ending in the current substree structure.
        // T0 represents an zero array.
        T = d[x];
        d[x] = T0;
        for (int p1 = 0; p1 <= m; p1++) {
            for (int k1 = 0; k1 <= p1; k1++) {
                for (int p2 = 0; p1 + p2 - 1 <= m; p2++) {
                    for (int k2 = 0; k2 <= p2; k2++) {
                        if (k2) {
                            if (k1) {
                                d[x].a[p1+p2-1][k1-1] = (d[x].a[p1+p2-1][k1-1] + T.a[p1][k1] * d[to].a[p2][k2] % P * k1 * k2) % P;
                            }
                            d[x].a[p1+p2][k1+1]=(d[x].a[p1+p2][k1+1]+T.a[p1][k1]*d[to].a[p2][k2]%P*k2)%P;
                        }

                        d[x].a[p1+p2][k1]=(d[x].a[p1+p2][k1]+T.a[p1][k1]*d[to].a[p2][k2])%P;
                        if (k1) {
                            d[x].a[p1+p2][k1-1]=(d[x].a[p1+p2][k1-1]+T.a[p1][k1]*k1%P*d[to].a[p2][k2])%P;
                        }
                        d[x].a[p1+p2+1][k1+1]=(d[x].a[p1+p2+1][k1+1]+T.a[p1][k1]*d[to].a[p2][k2])%P;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    // Any node can be root in a tree.
    // We use 1 as the start point.
    go(1,1);
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = (ans + d[1].a[m][i]) % P;
    }
    cout << ans << endl;

    return 0;
}
