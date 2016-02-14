#include <iostream>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll P = 1000000007;

// Let's save some info about tree at the process of construction:
// 1) answer - sum of distances.
// 2) X - sum of distances from "corner".(node which will connect to new one).
// 3) Y - number of nodes.
// 4) Z - "diameter" of tree, distance from one corner to diametrical one.

// In each step these values will change, but these values are enough to calculate new ones.
// formulas are quite easy to calculate: 
// NewAnswer = Answer * 4 + (Y * 12 + 8) * (X + Y * Ai) + (Y * 2 + 1)^2*Ai
// NewX = X * 4 + (Z + Ai * 2) * Y + (Z + Ai * 3) * Y * 2 + Z * 2 + Ai * 3
// NewY = Y * 4 + 2
// NewZ = Z * 2 + Ai * 3

// NewAnswer = Answer * 4 + [(Ai * Y + X) * 2 + (Ai * 2 * Y + X) * 2] * 2 + 
// (Y^2 * 2 * Ai + Y * X * 2) * 2 + (Y^2 * 3 * Ai + Y * X * 2) * 4 + Ai
// Confirmed it is correct.

int main() {
    ll n;
    cin >> n;
    // Initial values.
    ll res = 0;
    ll X = 0;
    ll Y = 1;
    ll Z = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        
        // It is tricky to get accepted in large testcases.
        // especially we need to divide one expression into two
        // to reduce the chance of overflow (X + Y * Ai) may be kind of large.
        ll newRes = res * 4 + (Y * 12 + 8) % P * X %P + 
            (Y * 12 + 8) % P * Y %P * ai +
            (Y * 2 + 1) % P * (Y * 2 + 1) % P * ai ;
        ll newX = X * 4 + (Z + ai * 2)%P * Y %P + (Z + ai * 3) %P * Y %P * 2 + Z * 2 + ai * 3;
        ll newY = Y * 4 + 2;
        ll newZ = Z * 2 + ai * 3;
        res = newRes % P;
        X = newX % P;
        Y = newY % P;
        Z = newZ % P;

    }
    cout << res << endl;
}
