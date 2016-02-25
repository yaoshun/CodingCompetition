#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> res(41, 1);

ll gcd(ll m, ll n) {
    if (m == 0) {
        return n;
    }
    if (n == 0) {
        return m;
    }
    if (m < n) {
        return gcd(m, n % m);
    } else {
        return gcd(n, m % n);
    }
}

ll lcm(ll m, ll n) {
    return m * (n / gcd(m, n));
}

void preprocessing() {
    res[1] = 1;
    for (int i = 2; i <= 40; i++) {
        res[i] = lcm(res[i - 1], i);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // these problem is finding least common multiple of 1,2...N.
    preprocessing();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}

