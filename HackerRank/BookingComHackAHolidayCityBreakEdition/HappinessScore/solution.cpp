#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX 1800001

bool isPrime[MAX];
using namespace std;

void sieve() {
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAX; i++) {
        isPrime[i] = true;
    }

    for (int i = 2; i * i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += nums[j];
            }
        }
        if (isPrime[sum]) {
            // no double counting.
            isPrime[sum] = false;
            res++;
        }
    }
    cout << res << endl;

    return 0;
}
