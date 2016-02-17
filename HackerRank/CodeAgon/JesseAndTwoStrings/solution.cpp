#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;

    while (T--) {
        string A;
        string B;
        cin >> A >> B;
        // The key problem here is the subsequence that forms the palindrome.
        // In this case we couldn't use the hashmap to solve the problem.
        // Instead we should use the DP.
        int m = A.size();
        int n = B.size();

        // lps[i][j] represents the longest palindromic subsequence constructive length, 
        // excluding A[i] to A[j], inclusive.
        // lps[i + 1][i] represents exclude nothing. For the last char, there is a overflow at zero.
        vector<vector<int>> lpsa(m, vector<int>(m, 0));
        vector<vector<int>> lpsb(n, vector<int>(n, 0));

        // solve the problem for A.
        for (int delta = m - 1; delta >= 0; delta--) {
            for (int i = 1; i + delta + 1 < m; i++) {
                if (A[i - 1] == A[i + delta + 1]) {
                    lpsa[i][i + delta] = lpsa[i - 1][i + delta + 1] + 2;
                } else {
                    lpsa[i][i + delta] = max(lpsa[i - 1][i + delta], lpsa[i][i + delta + 1]);
                }
            }
        }

        for (int delta = n - 1; delta >= 0; delta--) {
            for (int i = 1; i + delta + 1 < n; i++) {
                if (B[i - 1] == B[i + delta + 1]) {
                    lpsb[i][i + delta] = lpsb[i - 1][i + delta + 1] + 2;
                } else {
                    lpsb[i][i + delta] = max(lpsb[i - 1][i + delta], lpsb[i][i + delta + 1]);
                }
            }
        }

        int ma = 0;
        int mb = 0;
        for (int i = 0; i < m; i++) {
            ma = max(ma, lpsa[i][i] + 1);
            if (i < m - 1 && A[i] == A[i + 1]) {
                ma = max(ma, lpsa[i][i + 1] + 2);
            }
        }

        for (int i = 0; i < n; i++) {
            mb = max(mb, lpsb[i][i] + 1);
            if (i < n - 1 && B[i] == B[i + 1]) {
                mb = max(mb, lpsb[i][i + 1] + 2);
            }
        }

        if (ma % 2 == 0 || mb % 2 == 0) {
            cout << ma + mb << endl;
        } else {
            int res = ma + mb - 1;
            unordered_set<char> mp;
            for (int i = 0; i < m; i++) {
                if (lpsa[i][i] == ma - 1) {
                    mp.insert(A[i]);
                }
            }

            for (int i = 0; i < n; i++) {
                if (lpsb[i][i] == mb - 1 && mp.find(B[i]) != mp.end()) {
                    res++;
                    break;
                }
            }
            cout << res << endl;
        }
    }
    return 0;
}

