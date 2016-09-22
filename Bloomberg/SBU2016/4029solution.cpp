#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

int N;

int main() {
  cin >> N;
  vector<int> w(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i];
  }

  // Find the maximum sum of a nondecreasing subsequence.
  // dp[i] represents last cake i.
  vector<int> dp(N);
  dp[0] = w[0];
  for (int i = 1; i < N; i++) {
    dp[i] = w[i];
    for (int j = 0; j < i; j++) {
      if (w[j] <= w[i]) {
        dp[i] = max(dp[i], w[i] + dp[j]);
      }
    }
  }

  int res = dp[0];
  for (int i = 1; i < N; i++) {
    res = max(res, dp[i]);
  }
  cout << res << endl;
  return 0;
}
