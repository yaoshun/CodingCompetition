#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Wrong: 
// The output will be C(n, n/2) * (n/2)! = (n/2 + 1)*..(n) = f(n).
// since T is large, n is in a range, we need to precalculate.
// f(n - 2) = (n/2) * (n/2 + 1)...(n - 2)
// f(n) - f(n - 2) = (n/2 + 1)...(n - 2) (n^2 - n - n/2) = f(n - 2) * (2n - 3)
// f(n) = f(n - 2) * (2n - 2)

// Correct:
// No need to be palindrome.
// f(n) = n!

#define MAX 500001

typedef long long ll;
const ll P = 1000000007;

ll res[MAX];

void preprocessing() {
    res[1] = 2;
    for (int i = 2; i < MAX; i++) {
        res[i] = res[i - 1] * (2 * i - 1) % P * (2 * i)  % P;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    preprocessing();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << res[n/2] << endl;
    }
    return 0;
}

