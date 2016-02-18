#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

#define INF 99999999
#define MAX 3001
vector<pair<int,int>> adj[MAX];
int d[MAX];

void dijkstra(int* d, int s, int n) {
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
    }

    d[s] = 0;
    set<pair<int, int>> st;
    st.insert({0, s});
    while (!st.empty()) {
        pair<int,int> top = *st.begin();
        st.erase(st.begin());
        int val = top.first;
        int node = top.second;
        for (auto pair : adj[node]) {
            int nn = pair.second;
            int cost = pair.first;
            if (d[nn] > val + cost) {
                if (d[nn] != INF) {
                    st.erase(st.find({d[nn], nn}));
                }
                d[nn] = val + cost;
                
                st.insert({d[nn], nn});
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int n,m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int x,y,w;
            cin >> x >> y >> w;
            adj[x].push_back({w, y});
            adj[y].push_back({w, x});
        }
        int s;
        cin >> s;

        dijkstra(d, s, n);
        bool first=true;
        for (int i = 1; i <= n; i++) {
            if (i != s) {
                if (first) {
                    if (d[i] == INF) {
                        cout << -1;
                    } else {
                        cout << d[i];
                    }
                    first = false;
                } else {
                    if (d[i] == INF) {
                        cout << " " << -1;
                    } else {
                        cout << " " << d[i];
                    }
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
