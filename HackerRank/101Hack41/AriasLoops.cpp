#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

#define INF 1000000007LL

ll power(ll a, ll b) {
    ll x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>INF) x%=INF;
        }
        y = (y*y);
        if(y>INF) y%=INF;
        b /= 2;
    }
    return x;
}
 
ll modInverse(ll a) {
    return power(a, INF - 2) % INF;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll n, k;
    cin >> n >> k;
    for (ll i = k - 2; i >= 0; i--) {
        n -= i;
    }
    
    if (n < k) {
        cout << 0 << endl;
        return 0;
    }
    
    ll res = 1;
    
    // C(n, k) is the result now.
    for (ll i = 1; i <= k; i++) {
        res = res * (n + 1 - i) % INF;
        res = res * modInverse(i) % INF;
    }
    cout << res << endl;
    return 0;
}
