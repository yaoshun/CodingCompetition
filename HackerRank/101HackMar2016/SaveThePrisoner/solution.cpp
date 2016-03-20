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
        ll n, m, s;
        cin >> n >> m >> s;
        ll res = (s - 1 + m - 1) % n + 1;
        cout << res << endl;
    }
    return 0;
}

