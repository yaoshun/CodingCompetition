#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
ll a[300001];
ll b[300001];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ll C, M, n;
    cin >> C >> M >> n;
    
    a[0] = 0;
    b[0] = C;
    
    unordered_map<ll, vector<ll>> cset;

    ll cycle = n;
    
    for (int i = 1; i <= n; i++) {
        a[i] = (a[i - 1] + b[i - 1]) % M;
        b[i] = (b[i - 1] + a[i]) % M;
        if (cset.find(a[i]) == cset.end()) {
            cset[a[i]].push_back(b[i]);
        } else {
            for (auto p : cset[a[i]]) {
                if (p == b[i]) {
                    // cycle detected
                    // check how many in the cycle can be squared.
                    cycle = i - 1;
                    break;
                }
            }
            if (cycle != n) {
                break;
            } else {
                cset[a[i]].push_back(b[i]);
            }
        }
    }
    
    unordered_set<ll> st;
    for (int i = 1; i <= min(cycle, n); i++) {
        for (int j = 1; j < i; j++) {
            ll temp = (a[i] * a[j]) % M + (b[i] * b[j]) % M;
            temp %= M;
            st.insert(temp);
        }
    }
    
    if (cycle < n) {
        // Possible squares in the cycle. multiplied with itself in the other position.
        for (int i = 1; i <= min(n - cycle, cycle); i++) {
            ll temp = (a[i] * a[i]) % M + (b[i] * b[i]) % M;
            temp %= M;
            st.insert(temp);
        }
    }
    
    cout << st.size() << endl;
    
    return 0;
}

