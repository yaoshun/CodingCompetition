#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

int R, C, N;

int remove_tenants(int &K, int max_remove, int remove_cost) {
    int removed = min(K, max_remove);
    K -= removed;
    return removed * remove_cost;
}

// corners can reduce 2, while inners can reduce 4
// sides equals all - corners and inners and can reduce 3.
int get_score(int all, int corners, int inners) {
    int sides = all - corners - inners;
    int K = R * C - N;
    int unhappiness = R * C * 2 - R - C; // (R - 1) * C + (C - 1) * R
    unhappiness -= remove_tenants(K, inners, 4);
    unhappiness -= remove_tenants(K, sides, 3);
    unhappiness -= remove_tenants(K, corners, 2);
    return unhappiness;
}

int min_unhappiness() {
    // Fill in the tenants with a checkerboard
    // configuration, when one of R or C is even. 
    // we use the even side to decide.
    // When both of them are odd, we fill in the middle
    // then determine the rest (this is the better configuration
    // of the two)
    if (N <= (R * C + 1) / 2) return 0;

    // C >= R
    if (R == 1) {
        int K = R * C - N;
        int res = C - 1;
        int remove_cost = 2;
        return res - K * remove_cost;
    }

    // In these scenarios, we consider the process of removing
    // tenants to get the maximum decreasing of the scores.
    if (R % 2 == 1 && C % 2 == 1) {
        // 2.3.2
        // .4.4.
        // 3.4.3
        // .4.4.
        // 2.3.2
        int pattern1 = get_score((R*C + 1)/2, 4, ((R-2)*(C-2) + 1)/2);
        // .3.3.
        // 3.4.3
        // .4.4.
        // 3.4.3
        // .3.3.
        // The second configuration has more 3 unhappiness reduction
        // thus need to be considered.
        int pattern2 = get_score((R*C)/2, 0, (R-2)*(C-2)/2);
        return min(pattern1, pattern2);
    }

    // One of R and C is even number.
    // .3.2      2.3.      2.3.2
    // 3.4.  or  .4.3  or  .4.4.
    // .4.3      3.4.      3.4.3
    // 2.3.      .3.2      .3.3.
    return get_score(R*C/2, 2, (R-2)*(C-2)/2);
}

void solve() { 
    cin >> R >> C >> N;
    if (R > C) swap(R, C);
    cout << min_unhappiness() << endl;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": ";
        solve();
    }    
    return 0;
}
