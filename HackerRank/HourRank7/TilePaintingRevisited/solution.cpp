#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll P = 1e9 + 7;
/*
 The mathematical deduction is the key to this problem: To count all the possbiel arithmetic progressions (AP) uniquely and non repetitively,
 1. we consider the trivial case of one element, N.
 2. For APs with multiple elements, each AP has common difference D and size S will starts at some F and ends at F + (S - 1) * D.
 3. In other words, if we determined S and D, the number range to be [1,N], the number of possible APs are F >= 1, F + (S - 1) * D <= N, F has N - (S - 1)*D choices.
 4. Therefore we are actually calculating a series in the following format:
 \sum_{2<=S<=N}\sum_{1<=D<=N-1}(N - (S - 1)*D)
 or \sum_{1<=S<=N-1}\sum_{1<=D<=N-1}(N-S*D)
 */

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        // Since S and D is assymetric, we can calculate the case of
        // S < D and multiply it by two.
        ll n;
        cin >> n;
        ll res = 0;
        

        // we only evaluate the entries S * D < N.
        // and S < D.
        for (ll S = 1; S * S < n; S++) {
            ll maxD = n / S;
            // D can range from S + 1 to maxD.
            ll a = maxD + 1 + S;
            ll b = maxD - S;
            if ((maxD - S) % 2 == 0) {
                b = (b / 2) % P;
            } else {
                a = (a / 2) % P;
            }

            // Everything should mod P even before the multiplication to ensure correctness.
            res += (((maxD - S) % P) * (n % P) % P - (a % P) * (b % P) % P * (S % P) % P + P) % P;
            res %= P;
        }
        
        res = res * 2 % P;
         
        // This case count S == D problem.
        for (ll S = 1; S * S < n; S++) {
            res = (res + (n - S * S)) % P;
        }
        
        // Finally add single element case.
        res = (res + n) % P;
        cout << res << endl;
    }
    return 0;
}
