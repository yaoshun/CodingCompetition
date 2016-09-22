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
typedef long long ll;
#define INF 1000000007

int S;

int main() {
    cin >> S;
    vector<int> delegate(S);
    int sumdelegates;
    vector<int> cost(S);
    for (int i = 0; i < S; i++) {
        string state;
        int us;
        int them;
        cin >> state >> us >> them >> delegate[i];
        int undecided = 100 - us - them;
        if (us > them) {
            cost[i] = 0;
        } else if (them < 50){
            cost[i] = (them - us + 1) * 1;
        } else {
            cost[i] = (them - 49) * 3 + (undecided == 0 ? 0 : (undecided - 1));
        }
        sumdelegates += delegate[i];
    }
    
    int target = sumdelegates / 2 + 1;
    // Minimum cost to achieve a certain target.
    vector<pair<int, int>> input;
    for (int i = 0; i < S; i++) {
        if (cost[i] == 0) {
            target -= delegate[i];
        } else {
            input.push_back(make_pair(cost[i], delegate[i]));
        }
    }
    
    // No need to cost at all.
    if (target <= 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int m = input.size();
    
    // dp[i][j] means min cost with 0-i item to reach target j delegates.
    vector<vector<int>> dp(m + 1, vector<int>(target + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= target; j++) {
            if (j >= input[i-1].second) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - input[i - 1].second] + input[i - 1].first);
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][0] + input[i - 1].first);
            }
        }
    }
    cout << dp[m][target] << endl;
    
    return 0;
}

