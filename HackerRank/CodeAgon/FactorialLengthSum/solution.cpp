#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1000001
typedef long long ll;
using namespace std;

ll cnt[MAX];

void sieve() {
    for (int i = 0; i < MAX; i++) {
        cnt[i] = 0;
    }

    // This sieve calculate the number of prime factors.
    // and directly get the factorial length of x.

    // Another algorithm is to directly updates the following, but its complexity is not good.
    // The factorial length of x! depends on all the primes below x.
    // for prime p. x/p + x/p^2 + x/p^3.
    for (int i = 2; i < MAX; i++) {
        if (cnt[i] != 0) {
            // i is a composite.
            continue;
        }

        // i is a prime in this case.
        for (int j = i; j < MAX; j += i) {
            // calculate the sum power of prime factors in x. 
            int k = j;
            while (k%i == 0) {
                cnt[j]++;
                k = k / i;
            }
        }
    }

    for (int i = 1; i < MAX; i++) {
        cnt[i] = cnt[i] + cnt[i - 1];
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Preprocessing. 
    sieve();    

    int n;
    cin >> n;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i]; 
    }

    // Bit manipulation to get all the subsequences excluding the empty one.
    // subsequence means it can be non-continuous.
    ll total = 1 << n;
    ll count = 0, res = 0;
    for (int i = 1; i < total; i++) {
        count = 0;
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                count += cnt[nums[j]];
            }
        }

        if (count % 2 == 0) {
            res += count;
        }
    }

    cout << res << endl;
    return 0;
}

