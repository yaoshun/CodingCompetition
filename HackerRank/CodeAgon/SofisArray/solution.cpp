#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

#define P 1000000009
const int M = 17;

// 17 represents the length of maximum 2^17 = 131072 >100000
// a[x][y] = represents the multiply of segment [y, y + 2^x - 1]
// a[x][y] = Mul(a[x - 1][y], a[x - 1][y + 2^(x-1)])
ll a[M][100001];
ll k;

// dp array of the results.
// need to use d[n + 1] = 1.
// Which means using zero components of the previous.
ll d[100002];

// This is the way to calculate (A x B) % C where A,B < C <= 10^18.
// A x B is more than 64 bit integer.
// As a result, we do it bitwisely to solve the problem.
ll mu(ll x, ll y) {
    ll z = 0;
    while (y) {
        if (y&1) {
            z = z+x < k ? z+x : z+x-k;
        }
        y >>= 1;
        x = x+x < k ? x+x : x+x-k;
    }
    return z;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[0][i];
        a[0][i] %= k;
    }

    for (int j = 0; j + 1 < M; j++) {
        for (int i = 1; i <= n; i++) {
            if (i + (1 << j) <= n) {
                // make sure i + (1 << j) is not out of range.
                // out of range means 1.
                a[j + 1][i] = mu(a[j][i], a[j][i + (1<<j)]);
            } else {
                a[j + 1][i] = a[j][i];
            }
        }
    }

    // d is the dp array.
    // d[n + 1] means empty array.
    d[n + 1] = 1;
    int x;
    ll y,z;

    for (int i = n; i >= 1; i--) {
        d[i] = 0;
        x = i;
        y = 1;

        for (int j = M - 1; x <= n && j >= 0; j--) {
            // from x to x + 2^j - 1.
            z = mu(y, a[j][x]);
            if (z != 0) {
                x += (1<<j);
                y = z;
            }
        }

        // find i to max x so that segment [i, x] is just divisible.
        // z tracks the segment sum from [i, x - 1].
        // therefore i to x is the first divisible component 
        // "d" is here used as the solutions cumulative sum.
        // d[i] = sum(dp[0] + dp[1] + .. + dp[i])
        // then the following and the results make sense.
        if (x <= n) {
            // means z is zero.
            d[i] = d[x + 1];
        }
        d[i] = (d[i] + d[i+1]) % P;
    }

    cout << (d[1] - d[2] + P) % P << endl;

    return 0;
}

