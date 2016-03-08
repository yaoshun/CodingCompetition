#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

// bit requires one more index.
#define MAX 1000002
typedef long long ll;

int n;
ll c[MAX];
ll b[MAX];
ll bit[MAX];

void update(int ind, ll val) {
    while (ind <= n) {
        bit[ind] += val;
        ind += (ind & -ind);
    }
}

ll query(int ind) {
    ll res = 0;
    while (ind > 0) {
        res += bit[ind];
        ind -= (ind & - ind);
    }
    return res;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ll psum = 0;
    // set acts with the function of sort and unique.
    set<ll> st;
    st.insert(psum);
    for (int i = 0; i < n; i++) {
        psum += c[i] - b[i];
        st.insert(psum);
    }

    unordered_map<ll, ll> mp;
    // since the bit index start from 1.
    int cnt = 1;
    for (auto x : st) {
        mp[x] = cnt;
        cnt++;
    }

    ll ans = 0;
    psum = 0;
    update(mp[psum], 1);
    for (int i = 0; i < n; i++) {
        psum += c[i] - b[i];
        // query is inclusive.
        ans += query(mp[psum]);
        update(mp[psum], 1);
    }
    cout << ans << endl;
    return 0;
}
