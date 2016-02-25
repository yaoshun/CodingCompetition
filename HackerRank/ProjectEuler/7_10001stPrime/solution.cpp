#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> primes(200001, true);
vector<int> arr;

void sieve() {
    primes[0] = false;
    primes[1] = false;
    // additional primes have to be push back into arr.
    int i;
    for (i = 2; i * i <= 200000; i++) {
        if (primes[i]) {
            arr.push_back(i);
            for (int j = 2 * i; j <= 200000; j += i) {
                primes[j] = false;
            }   
        }   
    }
    for (;i <= 200000; i++) {
        if (primes[i]) {
            arr.push_back(i);
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    sieve();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << arr[n - 1] << endl;
    }
    return 0;
}

