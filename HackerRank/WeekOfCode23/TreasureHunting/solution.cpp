#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    // a' + b'i = (a + bi) * e(pi/2*i) = (a + bi) * (0 + i) = -b + ai
    // a' = -b; b' = a;
    // solve ak - bn = x and bk + an = y.
    // k = (xa + yb)/(a^2 + b^2)
    // n = (ay - bx)/(a^2 + b^2)
    double k = ((double)x * a + (double)y * b) / ((double)a * a + (double)b * b);
    double n = ((double)y * a - (double)x * b) / ((double)a * a + (double)b * b);
    cout.precision(17);
    cout << fixed << k << endl;
    cout << fixed << n << endl;
    return 0;
}
