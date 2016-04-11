#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

// In the large case, the naive LCM method
// and simulation process would not easily work anymore.

ll countServed(ll time, vector<int>& nums) {
    if (time < 0) return 0;
    ll res = 0;
    for (int barber = 0; barber < nums.size(); barber++) {
        res += time / nums[barber] + 1;
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int B, N;
        cin >> B >> N;
        vector<int> nums(B);
        for (int i = 0; i < B; i++) {
            cin >> nums[i];
        }
        
        // Given a time point T, we know how many customers it has served.
        // Therefore we first locate at which time points the nth customer
        // will be served.
        ll st = 0;
        ll ed = (ll)100000 * N;
        while (st < ed) {
            ll mid = st + (ed - st) / 2;
            if (countServed(mid, nums) < N) {
                st = mid + 1;
            } else {
                ed = mid;
            }
        }
        // We find the first time points that the Nth customer will be served.
        // x barber started at the mid time point.
        ll x = N - countServed(ed - 1, nums);
        int res;
        for (int i = 0; i < B; i++) {
            if (ed % nums[i] == 0) {
                x--;
            }
            if (x == 0) {
                res = i + 1;
                break;
            }
        }
        
        cout << "Case #" << (t + 1) << ": " << res << endl;
    }
    return 0;
}

