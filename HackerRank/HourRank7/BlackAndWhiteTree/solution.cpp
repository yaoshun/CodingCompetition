#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 Because the original and resulting graphs are connected bipartite graphs, the decomposed components are bipartite as well.
 For a bipartite component, there are exactly 2 possible color configurations, and we have to select exactly 1 of them for each component such that the difference |nB - nW| in the result graph is minimal.
 
 For each decomposed component, there is a fixed difference between the number of white nodes, nW and the black nodes nB, |nB - nW| is fixed. We can calculate the difference for each component.
 
 To optimize the algorithm, there is a key observation: there are no more than sqrt(n) different values of the differences. (quick deduction, assuming there are x different values of the differences, the minimal nodes necessary is (1 + 1) + (1 + 2) + ... + (1 + x) = x * (x + 3) / 2 < n)
 There for we can find the minimum value of |nB - nW| using dynamic programming in O(n sqrt(n)).
 */

#define MAX 200002
int n, m;
vector<int> adj[MAX];
vector<pair<int, int>> v2[MAX];

vector<int> a(MAX, 0);
int w[2], w2[2];
vector<bool> visited(MAX, false);
vector<int> d(MAX, 0);
vector<int> fr(MAX, 0);

void dfs(int x, int y) {
    visited[x] = true;
    w[y]++;
    w2[y] = x;
    for (int i = 0; i < adj[x].size();i++) {
        if (!visited[adj[x][i]]) {
            dfs(adj[x][i], y^1);
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    // k is the sum of total difference.
    int k = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            // w array is for count the bipartite graph.
            w[0] = w[1] = 0;
            dfs(i, 0);
            
            k += abs(w[0] - w[1]);
            a[abs(w[0] - w[1])]++;
            
            // ensure the positive order of it.
            if (w[0] < w[1]) {
                swap(w2[0], w2[1]);
            }
            v2[abs(w[0] - w[1])].push_back({w2[0], w2[1]});
        }
    }
    
    d[0] = 0;
    // MAX means unreachable
    // We avoid the use of INT_MAX, since there might be d[j] + 1
    // in the following codes.
    for (int i = 1; i <= k; i++) {
        d[i] = MAX;
        fr[i] = -1;
    }
    
    // dp with the differences array a[i].
    // Find all the possible partial sums.
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            for (int j = 0; j + i <= k; j++) {
                if (d[i + j] > d[j] + 1) {
                    d[i + j]= d[j] + 1;
                    fr[i + j] = j;
                }
            }
            
            // After this for loop, there are only two states.
            // 0 means reachable, MAX means inreachable with the
            // entries from 1 to i with the count array a[i].
            for (int j = 1; j <= k; j++) {
                // cannot use more than a[i] number of i.
                if (d[j] > a[i]) {
                    d[j] = MAX;
                } else {
                    // recover for next cycle.
                    d[j] = 0;
                }
            }
        }
    }
    
    int ans = k;
    int kk = k;
    for (int i = 0; i <=k; i++) {
        if (d[i] < MAX) {
            if (ans > abs(k - 2 * i)) {
                ans = abs(k - 2 * i);
                kk = i;
            }
        }
    }
 
    // This is for avoid extreme case where k is the
    // best solution.
    if (kk == 0) {
        kk = k;
    }
    
    vector<pair<int, int>> ap;
    vector<int> BL, WH;
    int sz = kk;
    
    while (kk) {
        sz = kk - fr[kk];
        kk = fr[kk];
        BL.push_back(v2[sz].back().first);
        v2[sz].pop_back();
    }
    
    for (int i=0;i<=k;i++)
        while (v2[i].size()){
            WH.push_back(v2[i].back().first);
            v2[i].pop_back();
        }
    
    if (BL.size() && WH.size()){
        for (int i=0;i<BL.size();i++)
            ap.push_back({BL[i],WH[0]});
        for (int i=1;i<WH.size();i++)
            ap.push_back({BL[0],WH[i]});
    }
    
    cout<<ans<<" "<<ap.size()<<endl;
    for (int i=0;i<ap.size();i++)
        printf("%d %d\n",ap[i].first,ap[i].second);
    return 0;
    
    return 0;
}

