#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define INF 99999999
int d1[3001];
int d2[3001];

struct edge {
    int x,y;
    int r,t;
};

// Adjacent list. The problem has 3000 nodes at max. 
vector<pair<int,int>> adj[3001];

void dijkstra(int* d, int s, int n) {
    for (int i = 0; i <= n; i++) {
        d[i] = INF;
    }

    d[s] = 0;
    
    // BST implementation of Dijkstra algorithm.
    // The pair.first if the current tentative distance value.
    set<pair<int,int>> q;
    q.clear();
    q.insert({0, s});
    while (!q.empty()) {
        // Select the node with the smallest tentative distance.
        // Therefore, each edge is only used once.
        pair<int, int> top = *q.begin();
        q.erase(q.begin());
        int v = top.second;
        int d1 = top.first;
        for (auto pair : adj[v]) {
            int v2 = pair.second;
            int cost = pair.first;

            // Find a new short path to v2.
            // update v2.
            if (d[v2] > d[v] + cost) {
                if (d[v2] != INF) {
                    // Erase the old one.
                    if (q.find({d[v2], v2}) != q.end()) {
                        q.erase(q.find({d[v2], v2}));
                    }
                }
                // update the cost.
                d[v2] = d[v] + cost;

                // Also update d[v2] tentative distance to the BST. 
                q.insert({d[v2], v2});
            }
        }
    }
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,t,r,x,y,n,m,s,d;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }

        struct edge e[m + 1];
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> r >> t;
            e[i].x = x;
            e[i].y = y;
            e[i].r = r;
            e[i].t = t;
            adj[x].push_back({r, y});
            adj[y].push_back({r, x});
        }

        cin >> s >> d;

        // d1 is the Dijkstra lengths starting from s.
        // d2 is the Dijkstra lengths starting from s.
        dijkstra(d1, s, n);
        dijkstra(d2, d, n);
        
        // Default result doesn't use taxi.
        int res = d1[d];
        for (int i = 0; i < m; i++) {
            res = min(res, d1[e[i].x] + e[i].t + d2[e[i].y]);
            res = min(res, d1[e[i].y] + e[i].t + d2[e[i].x]);
        }

        if (res != INF) {
            cout << res << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}

