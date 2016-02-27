#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000

vector<bool> primes(MAX + 1, true);
// It's very likely to be out of range.
vector<int> primeArr;

void sieve() {
    primes[0] = false;
    primes[1] = false;
    // additional primes have to be push back into arr.
    int i;
    for (i = 2; i * i <= MAX; i++) {
        if (primes[i]) {
            primeArr.push_back(i);
            for (int j = 2 * i; j <= MAX; j += i) {
                primes[j] = false;
            }
        }
    }
    for (;i <= MAX; i++) {
        if (primes[i]) {
            primeArr.push_back(i);
        }
    }
}

int num_divisors(int n) {
    if (n % 2 == 0) {
        n /= 2;
    }
    
    int res = 1;
    int count = 0;
    int i = 0;
    
    while (n != 1) {
        int p = primeArr[i];
        count = 0;
        while (n % p == 0) {
            count++;
            n = n / p;
        }
        res *= (count + 1);
        i++;
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sieve();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        
        int res = 1;
        int lcnt = num_divisors(res);
        int rcnt = num_divisors(res + 1);
        while (lcnt * rcnt <= n) {
            res++;
            lcnt = num_divisors(res);
            rcnt = num_divisors(res + 1);
        }
        cout << res * (res + 1) / 2 << endl;
    }
    return 0;
}

