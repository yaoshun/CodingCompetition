#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000 
vector<bool> primes(MAX + 1, true);
vector<int> primeArr;

void sieve() {
    primes[0] = false;
    primes[1] = false;
    int i;
    for (i = 2; i * i <= MAX; i++) {
        if (primes[i]) {
            primeArr.push_back(i);
            // Filter start at the i * i.
            // Since number that is smaller than i * i should have
            // already been filtered out.
            for (int j = i * i; j <= MAX; j += i) {
                primes[j] = false;
            }
        }
    }

    // additional primes have to be push back into arr.
    for (;i <= MAX; i++) {
        if (primes[i]) {
            primeArr.push_back(i);
        }
    }
}

int num_coprime(int n) {
    int res = n;
    int count = 0;
    int i = 0;
    
    while (n != 1) {
        int p = primeArr[i];
        if (n % p == 0) {
            res = res / p * (p - 1);
        }
        while (n % p == 0) {
            n = n / p;
        }
        i++;
    }
    return res;
}

vector<int> coprimeCount(vector<int> A) {
    sieve();
    vector<int> B;
    for (int i = 0; i < A.size(); i++) {
        B.push_back(num_coprime(A[i]));
    }
    return B;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> B = coprimeCount(A);
    for (int i = 0; i < n; i++) {
        cout << B[i] << endl;
    }
    return 0;
}

