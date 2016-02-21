#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 1001
vector<pair<int,int>> adj[MAX];
bool used[MAX][1024];

// Notice that it limits the weight to be below 1024.
// As a result, the | operator cannot generate number bigger than 1024.
// Therefore, we can use 2D dp to check the problem.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x,y,w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 1024; j++) {
            used[i][j] = false;
        }
    }

    int s,t;
    cin >> s;
    cin >> t;

    queue<pair<int, int>> q;
    q.push({s, 0});
    used[s][0] = true;
    while (!q.empty()) {
        int node = q.front().first;
        int val = q.front().second;
        q.pop();
        for (auto pair : adj[node]) {
            int to = pair.first;
            int add = pair.second;
            // This is the key step to avoid repetitive search.
            // only when false become true, we should push it in.
            // the node in the queue is not an node only, it is the pair
            // of a node and a specific value.
            if (!used[to][add | val]) {
                used[to][add | val] = true;
                q.push({to, add | val});
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < 1024; i++) {
        if (used[t][i]) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}

