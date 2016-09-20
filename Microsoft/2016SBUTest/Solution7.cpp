#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

ll MOD = 1000000007;

ll power(ll y, ll x) {
  ll res = 1;
  while (x > 0) {
    if (x % 2 == 1) {
      res = res * y % MOD;
    } else {
    }
    x = x / 2;
    y = y * y % MOD;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll res = 1;
  ll psum = 1;
  for (int i = 1; i < n; i++) {
    res = res * power(power(2, arr[i - 1]) - 1, arr[i]);
    res = res % MOD;
    res = res * power(power(2, psum), arr[i]);
    res = res % MOD;
    res = res * power(4, arr[i] * (arr[i] - 1) / 2);
    res = res % MOD;
    psum += arr[i];
  }

  cout << res << endl;
  return 0;
}
