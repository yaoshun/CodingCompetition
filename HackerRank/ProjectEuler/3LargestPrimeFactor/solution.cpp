#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<bool> primes(1000001, true);

void sieve() {
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i * i <= 1000000; i++) {
        if (primes[i]) {
            for (int j = 2 * i; j <= 1000000; j += i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // We need the primes for up to 10^6.
    // If n cannot be divided by these primes, n is a prime.
    sieve();
    
    int T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        long long res = n;
        for (int i = 2; i <= 1000000 && i <= n; i++) {
            while (primes[i] && n % i == 0) {
                res = i;
                n /= i;
            }
        }
        
        // n should be left a big prime.
        // or it must have a smaller prime factor under 1000000. 
        if (n > res) {
            res = n;
        }
        
        cout << res << endl;
    }
    return 0;
}

