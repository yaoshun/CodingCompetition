#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// Task definition.
// Through some example test, we have learned that if we sort the tuples by x and then y, we
// can scan the whole array and use dynamic programming to solve the problem. 
// Assuming there is a total of "d" different y coordinates. 
// nums[d] represents the current max value we can get with the d = mp[y].

// Initially dp[0-d-1] = 0;
// when we add value w to dp[i], we need to update dp[i-(d-1)] = max(dp[i] + w, dp[i-(d-1)]).
// As we can see, this is a ranged partial max problem (instead of ranged partial sum in normal BIT)
// thus we define the partial sum psum[i] = max(dp[0],...,dp[i]) and use the BIT to solve it.
// In the BIT[j] represents the max between a certain range [j-j&(-j), to j]

typedef long long ll;
typedef tuple<int, int, int> iii;

// BIT implementation.
// Here t[i] represents.
void update(int i, ll x, vector<ll>& t) {
    for (; i < t.size(); i += i & -i) {
        t[i] = max(t[i], x);
    }
}

ll get(int i, vector<ll>& t) {
    ll res = 0;
    for (; i != 0; i -= i & -i) {
        res = max(res, t[i]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<iii> tr;
    vector<int> arr;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        arr.push_back(y);
        tr.push_back((iii){x, y, w});
    }

    sort(arr.begin(), arr.end());
    mp[arr[0]] = 0;
    int d = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            // Index each unique y coordinates.
            d++;
            mp[arr[i]] = d;
        }
    }
    vector<ll> BITree(d + 2, 0);

    sort(tr.begin(), tr.end());
    for (int i = 0; i < n; i++) {
        int y = mp[get<1>(tr[i])];
        int w = get<2>(tr[i]);
        update(y + 1, get(y + 1, BITree) + w, BITree);
    }
    cout << get(d + 1, BITree) << endl;
    return 0;
}
