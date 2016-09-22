#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;

#define INF LLONG_MAX

vector<unordered_map<int, ll>> adj(1005);
vector<int> path;
ll d[1005];

int N, M;
int A, B, K, G;

int main() {
    cin >> N >> M;
    cin >> A >> B >> K >> G;
    
    path.resize(G);
    for (int i = 0; i < G; i++) {
        cin >> path[i];
    }
    
    for (int i = 0; i < M; i++) {
        int x,y;
        ll w;
        cin >> x >> y >> w;
        adj[x][y] = w;
        adj[y][x] = w;
    }
    
    // Blocking time.
    // mp[x][y]=t means x and y is blocked starting from time t.
    unordered_map<int, unordered_map<int, ll>> mp;
    
    // in advance 5 min, therefore block -4, -3, -2, -1, 0.
    ll time = -K + 1;
    for (int i = 0; i < path.size() - 1; i++) {
        mp[path[i]][path[i + 1]] = time;
        mp[path[i+1]][path[i]] = time;
        time += adj[path[i]][path[i+1]];
    }
    
    // Dijistra algorithm.
    for (int i = 1; i <= N; i++) {
        d[i] = INF;
    }
    d[A] = 0;
    set<pair<ll, int>> st;
    st.insert(make_pair(0, A));
    
    while (!st.empty()) {
        pair<ll, int> top = *st.begin();
        st.erase(st.begin());
        ll val = top.first;
        int node = top.second;
        for (auto pair : adj[node]) {
            int nn = pair.first;
            ll cost = pair.second;
            ll target;
            
            // Check whether there is a block.
            if (val < mp[node][nn] || val >= mp[node][nn] + adj[node][nn]) {
                // no blocking.
                target = val + cost;
            } else {
                // blocking, arrive after cleaner finish.
                target = mp[node][nn] + adj[node][nn] * 2 - 1;
            }
            
            if (d[nn] > target) {
                if (d[nn] != INF) {
                    st.erase(st.find(make_pair(d[nn], nn)));
                }
                d[nn] = target;
                st.insert(make_pair(d[nn], nn));
            }
        }
    }
    
    cout << d[B] << endl;
    
    return 0;
}

