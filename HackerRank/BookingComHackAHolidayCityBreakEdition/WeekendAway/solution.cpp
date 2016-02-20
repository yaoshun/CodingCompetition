#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define MAX 100001 
pair<int, int> minPair[MAX];

void push(pair<int, int>* minPair, int i, int w) {
    if (w < minPair[i].first) {
        minPair[i].second = minPair[i].first;
        minPair[i].first = w;
    } else if (w < minPair[i].second) {
        minPair[i].second = w;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

        // Assume there is no repetition of the same edge.
        for (int i = 1; i <= n; i++) {
            minPair[i].first = INT_MAX;
            minPair[i].second = INT_MAX;
        }

        for (int i = 0; i < m; i++) {
            int x, y, w;
            cin >> x >> y >> w;
            push(minPair, x, w);
            push(minPair, y, w);
        }

        int res = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (minPair[i].first != INT_MAX && minPair[i].second != INT_MAX) {
                res = min(res, minPair[i].first + minPair[i].second);
            }
        }
        cout << res << endl;
    }
    return 0;
}
