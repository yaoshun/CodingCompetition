#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string t;
string sentence;
vector<string> words;

// Failed a 3 test cases.
// The case fails in second part of not calculating the min cost.
// The min cost is independent of the first question.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cin >> t;
    string tmp;
    while (cin >> tmp) {
        words.push_back(tmp);
        sentence += tmp + " ";
    }
    // Remove the last space.
    sentence.pop_back();
    
    int cur = 0;
    vector<pair<string, int>> found;
    for (int i = 0; i < words.size(); i++) {
        int foundPos = t.find(words[i], cur);
        if (foundPos != string::npos) {
            cur = foundPos + 1;
            found.push_back(make_pair(words[i], foundPos));
        } else {
            break;
        }
    }
    
    if (found.size() == words.size()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    
    if (found.size() == 0) {
        cout << "0\n";
    } else {
        for (int i = 0; i < found.size(); i++) {
            cout << found[i].first << " " << found[i].second << " " << (found[i].second + found[i].first.size() - 1);
            if (i < found.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    // third line;
    if (found.size() == words.size()) {
        int m = t.size();
        int n = sentence.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++) dp[i][0] = i;
        for (int i = 1; i <= n; i++) dp[0][i] = i;
        
        // Just Edit distance calculation.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Since there is no replacement operation.
                // Add INF = 999999999 to avoid the problem.
                dp[i][j] = min(dp[i-1][j], dp[i][j - 1]) + 1;
                if (t[i-1] == sentence[j-1]) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                }
            }
        }
        cout << dp[m][n] << "\n";
    } else {
        cout << "0\n";
    }
    
    return 0;
}
