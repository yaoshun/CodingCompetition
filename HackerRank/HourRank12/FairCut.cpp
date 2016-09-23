#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

#define INF 1e18

ll dp[3005][3005];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    // dp[i][j] represents first i number, with j number on one side and i - j
    // number on the other side.
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = INF;
        }
    }
    
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // Case one: nums[i] contributed to the k side.
            // In this case nums[i] contribute to total sum of nums[i] * (i - j - (n - k - (i - j))). 
            dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + nums[i] * (i - j - (n - k - (i - j))));
            // Case two: nums[i] contributed to the n - k side.
            // k side will not increase.
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + nums[i] * (j - (k - j)));
        }
    }
    
    cout << dp[n][k] << endl;
    
    return 0;
}
