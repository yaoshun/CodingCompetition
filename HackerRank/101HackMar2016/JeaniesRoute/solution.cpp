#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// The graph is definitely a tree with n - 1 edges among n nodes.
// but not necessarily a binary tree.
// The key property is that there are no loops existing in the tree.
// therefore dfs will definitely generate the best distance.
// We don't need a Dijkstra algorithm in this case.

#define MAX 500001
int n, k, sum, m;
int s[MAX];
bool f[MAX];
vector<int> v[MAX], d[MAX];

// x is the current node, from is the prev node.
// find two big diameters starting from x, D2 > D1 by default.
// return value is the maximal diameter value starting from x.
//
// During the process, it updated global variable m, which is the
// the global maximal diameter to be considered.
//
// If there is no target node in a tree branch, it will return -infinity.
int go(int x, int from) {
    // looks like select the top two distance.
    int D1 = INT_MIN;
    int D2 = INT_MIN;

    for (int i = 0; i < v[x].size(); i++) {
        // each iteration in the for loop will search to the end in the current path.
        if (v[x][i] != from) {
            D1 = max(D1, go(v[x][i], x) + d[x][i]);
            if (D1 > D2) {
                swap(D1, D2);
            }

            // Sum the target node it could find through the path.
            s[x] += s[v[x][i]];

            // It means along the v[x][i] node there is at least one node.
            // but not all the nodes.
            // therefore it is a necessary edge for the loop.
            if ( 0 < s[v[x][i]] && s[v[x][i]] < k) {
                sum += d[x][i];
            }
        }
    }

    // m is for updating the diameters.
    if (D1 > 0) m = max(m, D1 + D2);

    // x is a target node.
    // in other scenarios, we don't need to touch the diameter.
    if (D2 > 0 && f[x]) m = max(m, D2);

    if (f[x]) D2 = max(D2, 0);

    return D2;
}

int main() {

    // Input part.
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        s[x] = 1;
        f[x] = true;
    }

    for (int i = 1; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back(y);
        v[y].push_back(x);
        d[x].push_back(z);
        d[y].push_back(z);
    }

    // Solving part.
    go(1, 1);
    cout << sum * 2 - m << endl;
    return 0;
}
