#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

// 1e-15 is enough to store the
// minimal distance of the difference in the 
long double eps = 1e-15;

void solve() {
    int n;
    cin >> n;
    int x[n], y[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    long double a[2 * n];
    for (int i = 0 ; i < n; i++) {
        int an = 0, ans = n - 1;
        for (int j = 0 ; j < n; j++) {
            if (j != i) {
                // atan2l function actually determines the quandrant with
                // the signs of its arguments.
                a[an] = atan2l((long double)(y[j] - y[i]), (long double)(x[j] - x[i]));
                an++;
            }
        }
        sort(a, a + an);
        for (int i = 0; i < an; i++) {
            a[i + an] = a[i] + 2 * M_PI;
        }

        int r = 0;
        // Using each point as a left,
        // find the first point that has a least M_PI difference. 
        for (int i = 0; i < an; i++) {
            while (r < 2 * an && a[r] - a[i] < M_PI - eps)
                r++;
            ans = min(ans, r - i - 1);
        }
        cout << ans << endl;
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": " << endl;
        solve();
    }    
    return 0;
}
