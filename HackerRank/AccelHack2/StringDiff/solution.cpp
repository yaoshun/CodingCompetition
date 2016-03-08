#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void zalgo(string& s, vector<int>& z) {
    int L = 0;
    int R = 0;
    int n = s.size();

    // z array z[0] is just undefined.
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R - L] == s[R]) {
                R++;
            }
            z[i] = R - L;
            R--;
        } else {
            // [L, R] is the rightmost region
            // that is a prefix of the string s.
            int k = i - L;
            if (z[k] < R - i + 1) {
                // In this case we already know the results.
                z[i] = z[k];
            } else {
                L = i;
                // We directly start to match at R position.
                while (R < n && s[R - L] == s[R]) {
                    R++;
                }
                z[i] = R - L;
                R--;
            }
        }
    }
}

int main() {
    string a, b;
    cin >> a >> b;
    int n1 = a.size();
    int n2 = b.size();
    vector<int> z1(n1 + n2, 0);
    vector<int> z2(n1 + n2, 0);

    string s = b + a;
    string t = a + b;
    reverse(t.begin(), t.end());

    // z1 matches from the front.
    // z2 matches from the backside.
    // if sum of them is one off n2, it means just
    // replace that char.
    zalgo(s, z1);
    zalgo(t, z2);

    int res = 0;
    for (int i = n2; i <= n1; i++) {
        if (z1[i] + z2[n1 + n2 - i] == n2 - 1) {
            res++;
        }
    }
    cout << res << endl;
}
