#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

const ll P = 1000000007;

int m = 2000000;
// In this problem we calculate C(n-1, k-1).
// Space complexity and time comlexity of O(m^2) is unacceptable
// in this case.
vector<vector<ll> > comb(m + 1, vector<ll>(m + 1, 0));

void preprocess() {
    comb[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % P;
        }
    }
}

int main() {
    preprocess();
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << comb[n - 1][k - 1] << endl;
    }
    return 0;
}
