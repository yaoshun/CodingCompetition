#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int n;
    cin >> n;
    vector<vector<ll>> grid(n, vector<ll>(n));
    vector<vector<ll>> score(n, vector<ll>(n, LLONG_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    set<pair<ll, pair<int, int>>> st;
    st.insert(make_pair(grid[0][0], make_pair(0,0)));
    score[0][0] = grid[0][0];
    while (!st.empty()) {
        pair<ll, pair<int, int>> top = *st.begin();
        st.erase(st.begin());
        ll val = top.first;
        int x = top.second.first;
        int y = top.second.second;
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            if (newx < 0 || newx >= n || newy < 0 || newy >= n) continue;
            if (score[newx][newy] > val + grid[newx][newy]) {
                if (score[newx][newy] != LLONG_MAX) {
                    st.erase(st.find(make_pair(score[newx][newy], make_pair(newx, newy))));
                }
                score[newx][newy] = val + grid[newx][newy];
                st.insert(make_pair(score[newx][newy], make_pair(newx, newy)));
            }
        }
    }
    
    cout << score[n - 1][n - 1] << endl;
    
    return 0;
}
