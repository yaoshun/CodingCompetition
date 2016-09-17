// This is for calculating power efficiently for long long.
typedef long long ll;

ll MOD = 1000000007;

ll power(ll y, ll x) {
  ll res = 1;
  while (x > 0) {
    if (x % 2 == 1) {
      res = res * y % MOD;
    }
    x = x / 2;
    y = y * y % MOD;
  }
  return res;
}
