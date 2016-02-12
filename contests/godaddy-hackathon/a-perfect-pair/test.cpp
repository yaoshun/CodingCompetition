#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, m, q;
    cin >> n >> m >> q;
    
    // Build the graph.
    vector<vector<int>> nn(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        nn[x - 1].push_back(y - 1);
        nn[y - 1].push_back(x - 1);
    }
    
    // Traverse the Graph and build the perfect pair set.
    vector<unordered_set<int>> res(n);
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        queue<int> q;
        visited[i] = true;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto& neighbors : nn[cur]) {
                if (visited[neighbors] == true) {
                    res[i].insert(neighbors);
                } else {
                    visited[neighbors] = true;
                    q.push(neighbors);
                }
            }
        }
    }
    
    // Output the result.
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (res[x - 1].find(y - 1) != res[x - 1].end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
