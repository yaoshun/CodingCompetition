#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

const ll P = 1000000007;
ll factorial[2000001];
// In this problem we calculate C(n-1, k-1).
// which is equivalent to (n - 1)! / (k - 1)!(n - k)!
// Since in the process of calculating factorials, we need to
// mode P, therefore the division becomes a problem to solve.
// Here we can use the Fermat theorem plus the modular multiplication
// to calculate the modular inverse, which can change the division
// into mudular multiplication.

// Calculate a ^ b % mod
ll pow(ll a, ll b, ll mod) {
    ll x = 1;
    ll y = a;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x * y);
            x %= mod;
        }
        y = y * y;
        y %= mod;
        b >>= 1;
    }
    return x;
}

// Fermat theorem a ^ (m - 1) = 1 mod m
// if gcd(a, m) = 1 and m is a prime.
ll modInverse(ll a, ll m) {
    return pow(a, m - 2, m);
}

void preprocess() {
    factorial[0] = 1;
    factorial[1] = 1;
    for (ll i = 2; i <= 2000000; i++) {
        factorial[i] = (factorial[i - 1] * i) % P;
    }
}

int main() {
    preprocess();
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        ll ans = factorial[n - 1];
        ans = (ans * modInverse(factorial[k - 1], P)) % P;
        ans = (ans * modInverse(factorial[n - k], P)) % P;
        cout << ans << endl;
    }
    return 0;
}
