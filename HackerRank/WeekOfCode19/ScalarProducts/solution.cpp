#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

// To even reduce the time complexity.
// we should use the fibonacci equality.
// F(n) x F(k) + F(n + 1) x F(k + 1) = F(n + k + 1)

typedef long long ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll C, M, n;
    cin >> C >> M >> n;

    // 1<= i, j <= n, i!=j can conclude that 3 <= i + j <= 2n - 1
    // O(n) time complexity with a hashset.
    // scalar product of i, j is actually F(2i) x F(2j) + F(2i + 1) x F(2j + 1) = F(2i + 2j + 1) * C
    unordered_set<ll> st;
   
    // 0:0, 1:1, 2:1, 3:2, 4:3, 5:5, 6:8
    ll a = 5*C%M;
    ll b = 8*C%M;

    for (int i = 3; i <= 2 * n - 1; i++) {
        // calculate F(2i + 1) in this case.
        a = (a + b) % M;
        st.insert(a * C % M);
        b = (b + a) % M;
    }
    
    cout << st.size() << endl;
    return 0;
}

