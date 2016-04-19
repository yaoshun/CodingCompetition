#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }

// To solve this problem, we need some knowledge about the prime theory
// and also the definition of primitive root modulo a prime p.
// The first thought is to brute force find the results, however with
// p up to 5x10^6, it will not work.
// Deducting from math theory, we focused on the primitive root of modulo p
// which can essentially generate all the possible modulos through exponentiation.

// Multiplication of 5*10^6 will require the incorporation of long long
// data type for security.

ll p;
vector<ll> log_p(5000001, 0);
vector<ll> exp_p(5000001, 0);

ll mul_inv(ll a, ll b) {
    ll b0 = b, t, q;
    ll x0 = 0, x1 = 1;
    if (b == 1) return 1;
    while (a > 1) {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0) x1 += b0;
    return x1;
}

bool is_generator(ll g) {
    ll cur = 1;

    // check g, g^2, ... to g^(p - 2)
    // According to Fermat theorem, g^(p-1) = 1 mod p.
    for (ll i = 0; i < p - 2; i++) {
        cur = cur * g % p;
        if (cur == 1) {
            return false;
        }
    }
    return true;
}

ll find_generator() {
    ll res = 1;
    while (!is_generator(res)) {
        res++;
    }
    return res;
}

vector<ll> get_ans(ll k, ll n) {
    vector<ll> res;
    n %= p;
    if (n < 0) n += p;
    if (n == 0) {
        res.push_back(0);
        return res;
    }

    // n is in the range of 1 to p - 1.
    // g^m = n mod p
    // then we are solving another problem of kX = m mod p - 1
    ll m = log_p[n];
    ll common_d = gcd(k, p - 1);
    if (m % common_d == 0) {
        // solve (k/common_d) X = (m/common_d) mod ((p - 1)/common_d)
        ll temp = mul_inv(k/common_d, (p-1)/common_d);
        ll X = (m/common_d) * temp % ((p - 1)/common_d);
        for (ll i = 0; i < common_d; i++) {
            // exp[X] is the acutal kth root.
            res.push_back(exp_p[X]);
            X += (p - 1) / common_d;
        }
        sort(res.begin(), res.end());
        return res;
    } else {
        // There are no solutions in this case.
        return res;
    }
}

int main() {
    cin >> p;
    ll g = find_generator();

    ll cur = 1;
    for (ll i = 0; i < p - 1; i++) {
        log_p[cur] = i;
        exp_p[i] = cur;
        cur = cur * g % p;
    }

    ll q;
    cin >> q;
    for (ll i = 0; i < q; i++) {
        ll k, n;
        cin >> k >> n;

        vector<ll> res = get_ans(k, n);
        if (res.empty()) {
            cout << "NONE" << endl;
        } else {
            cout << res[0];
            for (ll i = 1; i < res.size(); i++) {
                cout << " " << res[i];
            }
            cout << endl;
        }
    }

    return 0;
}
