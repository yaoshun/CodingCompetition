#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

// The key idea to solve the problem is 
//

int solve(vector<ll>& psum, int st, int ed) {
    ll sum = psum[ed + 1] - psum[st];
    if (sum % 2 == 1) {
        return 0;
    }
    ll target = sum / 2 + psum[st];
    
    // binary search original array index.
    int l = st;
    int r = ed;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (psum[mid + 1] == target && (mid == l || psum[mid] != target)) {
            return max(solve(psum, st, mid), solve(psum, mid + 1, ed)) + 1;
        } else if (psum[mid + 1] >= target) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> nums(n);
        vector<ll> psum(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            psum[i + 1] = psum[i] + nums[i];
        }
        
        cout << solve(psum, 0, n - 1) << endl;
    }
    return 0;
}

