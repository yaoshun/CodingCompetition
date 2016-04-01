#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

vector<ll> a(100000, 0);

// The key idea to solve this problem correctly is
// 1. to use the partial sum.
// 2. Notice that 0 in the array will cause problem during the calculation
// espercially when all the entries are zero.

// Here we use dynamic programming.

ll sum(int l, int r) {
    return a[r] - a[l - 1];
}

int get(int l, int r, ll s) {
    int st = l;
    int ed = r;
    while (st < ed) {
        int mid = st + (ed - st) / 2;
        ll x = sum(l, mid);
        // excluding the impact of 0.
        // 1. mid == l excluding the impact of all 0s.
        // 2. sum(l, mid - 1) != s gurantees the left most index which
        // will gurantee the generation of best score in the case of all 0s.
        if (x == s && (mid == l || sum(l, mid - 1) != s)) {
            return mid;
        } else if (x >= s) {
            ed = mid;
        } else {
            st = mid + 1;
        }
    }
    return -1;
}

int solve(int l, int r) {
    ll s = sum(l, r);
    if (l != r && s % 2 == 0) {
        int ind = get(l, r, s / 2);
        if (ind != - 1) {
            return max(solve(l, ind), solve(ind + 1, r)) + 1;
        }
    }
    return 0;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        // Use a[i] to store the partial sum.
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }

        // solve(st, ed) means solve the problem between array index st - 1 and ed - 1;
        cout << solve(1, n) << endl;
    }
    return 0;
}
