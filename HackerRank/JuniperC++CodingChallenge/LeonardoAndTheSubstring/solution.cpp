#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        // O(n) dynamic programming.
        // dp[i] represents the number of substrings ending in s[i].
        
        // s[0] case.
        long long res = 1;
        int cur = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                cur++;
                res += cur;
            } else {
                cur = 1;
                res += 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}

