#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#define INF 400
typedef long long ll;
using namespace std;

int numOfOnes(ll n) {
    int res = 0;
    while (n) {
        res += n & 1;
        n = n >> 1;
    }
    return res;
}

void solve() { 
    int N, L;
    cin >> N >> L;
    vector<ll> initial(N);
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        initial[i] = stoll(temp, nullptr, 2);
    }

    unordered_set<ll> st;

    vector<ll> target(N);
    for (int i = 0; i < N; i++) {
        cin >> temp;
        target[i] = stoll(temp, nullptr, 2);
        st.insert(target[i]);
    }

    // Brute force will need to consider the case of 2^L flippings
    // and corresponding matching.
    // If we consider matching first, we only need N^2 possible flipping 
    // strings, since there are only n^2 possible pairs of devices and outlets. 
    // Can be reduced to N since we must pair the first device to one of the remaining devices.
    vector<ll> cand;
    for (int j = 0; j < N; j++) {
        cand.push_back(initial[0] ^ target[j]);
    }

    // infinity.
    int res = INF;
    for (int i = 0; i < N; i++) {
        unordered_set<ll> temp_set = st;
        for (int j = 0; j < N; j++) {
            ll node = initial[j] ^ cand[i];
            if (temp_set.find(node) == temp_set.end()) {
                break;
            } else {
                temp_set.erase(node);
            }
        }

        if (temp_set.empty()) {
            res = min(res, numOfOnes(cand[i]));
        }
    }

    if (res == INF) {
        cout << "NOT POSSIBLE" << endl;
    } else {
        cout << res << endl;
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": ";
        solve();
    }    
    return 0;
}
