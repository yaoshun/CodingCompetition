#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll P = 1000000007;

// The key observation is that the value of i + j remains the same for any
// specific diagonal of the matrix.
// one diagonal must be strictly higher than all the values in the diagonal above it.
// Therefore the solution actually is actually d1! x d2! x ... x d(N+M - 1)! 
int n,m;
ll fact[2000005];

int main() {
    cin >> n >> m;

    // Precalculating the factorials.
    fact[0] = 1;
    for (int i = 1; i <= n + m; i++) {
        fact[i] = i * fact[i - 1] % P;
    }

    ll ans = 1;
    for (int sum = 0; sum < n + m - 1; sum++) {
        // number of element across the sum of i + j = sum.
        // 0 <= i <= n - 1, 0 <= j <= m - 1.
        int mini = max(0, sum - m + 1);
        int maxi = min(n - 1, sum);
        ans *= fact[maxi - mini + 1];
        ans %= P;
    }
    cout << ans << endl;
    return 0;
}
