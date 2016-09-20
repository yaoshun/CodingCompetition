#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll a[200005];
ll b[200005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;

    ll res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i] += b[i];
        res -= b[i];
    }

    sort(a, a + n);

    for (int i = 0; i < k; i++) {
        res += a[n - 1 - i];
    }
    if (res > 0) {
        cout << res << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
