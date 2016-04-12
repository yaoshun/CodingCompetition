#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

// This problem relies on the heuristics for the optimal
// couting process.
// Therefore, we should quickly raise some examples of how to 
// efficiently count the numbers to solve the large test case.

ll p10[10]; // p10[i] = 10^i;

bool is_1_followed_by_0s(string s) {
    reverse(s.begin(), s.end());
    return stoi(s) == 1;
}

int solve(ll n) { 
    if (n < 10) return n;

    string s = to_string(n);
    int M = s.size();

    int ans = 1;

    // Part 1: from 1, get to the m digits as soon as possible.
    for (int d = 1; d < M; d++) {
        // start with digits 7, 1000000
        // Count up to 9999, 1009999 
        ans += p10[(d + 1) / 2] - 1;
        // flip once, 9999001.
        if (d > 1) ans++;
        // Count up 999.
        ans += p10[d / 2] - 1;
    }

    // Part 2: 
    // Split N into two halves "1234567" to "123" and "4567"
    string L = s.substr(0, M/2);
    string R = s.substr(M/2);

    // Handles the case where the right half is all zeros.
    if (stoi(R) == 0) return solve(n - 1) + 1;

    // Special case: Count directly to the answer.
    if (is_1_followed_by_0s(L)) {
        return ans + stoi(R);
    }

    // Count until the right half looks like the left half of N.
    reverse(L.begin(), L.end());
    ans += stoi(L);

    // Flip.
    ans++;

    // Count again.
    ans += stoi(R) - 1;
    return ans;
}

int main() {
    // Preprocessing.
    p10[0] = 1;
    for (int i = 1; i < 10; i++) {
        p10[i] = 10 * p10[i - 1];
    }

    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": ";
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }    
    return 0;
}
