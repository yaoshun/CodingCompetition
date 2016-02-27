#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000000 

vector<bool> primes(MAX + 1, true);
// It's very likely to be out of range.
vector<long long> sum(MAX + 1, 0);

void sieve() {
    primes[0] = false;
    primes[1] = false;
    sum[2] = 2;
    // additional primes have to be push back into arr.
    int i;
    for (i = 2; i * i <= MAX; i++) {
        if (primes[i]) {
            sum[i] = sum[i - 1] + i;
            for (int j = 2 * i; j <= MAX; j += i) {
                primes[j] = false;
            }   
        } else {
            sum[i] = sum[i - 1];
        }
    }
    for (;i <= MAX; i++) {
        if (primes[i]) {
            sum[i] = sum[i - 1] + i;
        } else {
            sum[i] = sum[i - 1];
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sieve();
    int T;
    cin >> T;
    // Since T is large, we directly finished all the precalculation.
    while (T--) {
        int n;
        cin >> n;
        cout << sum[n] << endl;
    }
    return 0;
}

