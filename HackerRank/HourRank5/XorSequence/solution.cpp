#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

// Check array A.
// A[1] = 1
// A[2] = 1 ^ 2
// A[3] = 1 ^ 2 ^ 3
// Check partial sum array B.
// B[1] = 1
// B[2] = 2
// B[3] = 1 ^ 3
// B[4] = 2 ^ 4
// As a result, for odd indexes B[i] = 1 ^ 3 ^ ... i
// for even indexes B[i] = 2 ^ 4 ... i]
// The result is B[Ri] ^ B[Li - 1] using the fact that if a^b = c, then a^c = b.

ll factorial(ll x) {
    // x >= 1
    // Here calculate 1^2^3^...^x
    // We can prove that (4K) ^ (4K + 1) ^ (4K + 2) ^ (4K + 3) = 0
    ll res = 0;
    for (ll i = (x/4) * 4; i <= x; i++) {
        res = res ^ i;
    }
    return res;
}

ll calculateB(ll i) {
    if (i == 0) {
        return 0;
    }

    if (i % 2 == 0) {
        return factorial(i/2) * 2;
    } else {
        return factorial((i - 1)/2) * 2 + (((i-1)/2 + 1) % 2);
    }
}

int main(){
    int T;
    cin >> T;
    while (T > 0) {
        T--;
        ll l;
        ll r;
        cin >> l;
        cin >> r;
        // "l - 1" might be zero, return zero in which case.
        ll res = calculateB(l - 1) ^ calculateB(r);
        cout << res << endl;
    }
}

