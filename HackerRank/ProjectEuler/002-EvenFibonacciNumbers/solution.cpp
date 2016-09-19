#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

// Every three number there is an even number.
// Therefore we should investigate the relationship between
// F(i + 6), F(i + 3), F(i).
// Deduction is as follows: 
// 0:a
// 1:b
// 2:a + b
// 3:a + 2b
// 4:2a + 3b
// 5:3a + 5b
// 6:5a + 8b
// therefore F(n) = 4 * F(n - 1) + F(n - 2).

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // The complexity is log(n) since the series grows exponentially.
    // for even numbers F(n) = 4 * F(n - 1) + F(n - 2)
    int T;
    cin >> T;
    while (T--) {
        ll N;
        cin >> N;
        ll a = 0;
        ll b = 2;
        ll sum = 0;
        while (b <= N) {
            sum += b;
            ll temp = a + 4 * b;
            a = b;
            b = temp;
        }
        cout << sum << endl;
    }
    return 0;
}

