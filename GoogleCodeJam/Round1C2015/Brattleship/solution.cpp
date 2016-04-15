#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

void solve() { 
    int R, C, W;
    cin >> R >> C >> W;

    int res = 0;
    // Guesses necessary to cover the first right position.
    res += R * (C / W);

    // Once cover a hit, we need expand it through two side and need
    // W - 1 guesses. And our brother can mistake only my one shot,
    // therefore we need at most W  more guesses.
    res += W - 1;

    if (C % W) res++;

    cout << res << endl;
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
