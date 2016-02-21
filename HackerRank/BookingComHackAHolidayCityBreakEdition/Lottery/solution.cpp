#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define NIL 0
#define INF INT_MAX
using namespace std;

int m, n;

vector<int> adj[10001];
int pairU[10001];
int dist[10001];
int pairV[100001];

bool dfs(int u) {
    if (u != NIL) {
        for (int v : adj[u]) {
            if (dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v]) == true) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }

        dist[u] = INF;
        return false;
    }
    return true;
}

// Check if we could find an augmenting path in the scenario
// of the current matching scheme.
bool bfs() {
    queue<int> q;

    for (int u = 1; u <= m; u++) {
        if (pairU[u] == NIL) {
            dist[u] = 0;
            q.push(u);
        } else {
            dist[u] = INF;
        }
    }

    dist[NIL] = INF;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (dist[u] < dist[NIL]) {
            // Left to right use any adjacent.
            // righ to left use the current pairing.
            for (int v : adj[u]) {
                // Either it is free then pairV[v] = NIL.
                // Or it connects to a new u that we should continue to explore.
                // INF also means unvisited.
                // The visited u series of index will not have INF.
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    // non-infinity means there is NIL is coming from a pairV[v] file.
    // which means both end is empty
    return (dist[NIL] != INF);
}

int hopcroftKarp() {
    for (int u = 1; u <= m; u++) {
        pairU[u] = NIL;
    }

    for (int v = 1; v <= n; v++) {
        pairV[v] = NIL;
    }

    int res = 0;

    while (bfs()) {
        // Find a free vertex
        for (int u = 1; u <= m; u++) {
            if (pairU[u] == NIL && dfs(u)) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    // T is the left of the bipartite graph.
    // H is the right of the bipartite graph.
    cin >> m >> n;

    // This problem solves the maximum matching in bipartite graph.
    // vertex number estimation: T + H ~ 100000
    // edge number estimation: T * 20 ~ 200000
    // Hopcroft-Karp algorithm solves the problem with O(|E|sqrt(|V|)).
    for (int i = 1; i <= m; i++) {
        int e;
        cin >> e;
        int y;
        for (int j = 0; j < e; j++) {
            cin >> y;
            // Only one case, no need to clear the adj.
            adj[i].push_back(y);
        }
    }

    cout << (n - hopcroftKarp()) << endl;
    return 0;
}
