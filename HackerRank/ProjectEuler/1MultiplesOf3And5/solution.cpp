#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        // (sum of 3) + (sum of 5) - (sum of 15).
        ll n;
        cin >> n;
        ll res = 0;
        ll x = (n - 1) / 3;
        res += x * (x + 1) / 2 * 3;
        x = (n - 1) / 5;
        res += x * (x + 1) / 2 * 5;
        x = (n - 1) / 15;
        res -= x * (x + 1) / 2 * 15;
        cout << res << endl;
    }
    return 0;
}

