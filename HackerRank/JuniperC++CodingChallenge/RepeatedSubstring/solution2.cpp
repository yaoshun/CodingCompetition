#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define MAX 100001

// All arrays are zero by default.
int sa[MAX], pos[MAX], tmp[MAX], lcp[MAX];

string s;
int k;
int n;

int gap;

// this function returns false if equal.
bool sufCmp(int i, int j) {
    if (pos[i] != pos[j]) {
        return pos[i] < pos[j];
    }
    i += gap;
    j += gap;
    return (i < n && j < n) ? pos[i] < pos[j] : i > j;
}

// The building of the suffix array.
// O(n logn logn) algorithm.
void buildSA() {
    for (int i = 0; i < n; i++) {
        // value i means the suffix from i to the end.
        sa[i] = i;
        pos[i] = s[i];
    }

    for (gap = 1; ; gap *= 2) {
        // if gap = 1, it means sort according to
        // the first two chars of the suffix array.
        sort(sa, sa + n, sufCmp);
        for (int i = 0; i < n - 1; i++) {
            // true equals 1, false equals 0.
            // tmp[0] is always 0.
            tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        }
        for (int i = 0; i< n; i++) {
            // pos stores the current rank of the string
            // starting at sa[i] with the length gap.
            pos[sa[i]] = tmp[i];
        }

        // this means every suffix is not equal.
        // it has been figured out.
        if (tmp[n - 1] == n - 1) {
            break;
        }
    }
}

// The building of lcp relies on SA array.
void buildLCP() {
    for (int i = 0, k = 0; i < n; i++) {
        if (pos[i] != n - 1) {
            for (int j = sa[pos[i] + 1]; s[i + k] == s[j + k]; k++) {
            }
            lcp[pos[i]] = k;
            if (k) {
                k--;
            }
        }
    }
}

int main() {
    cin >> s;
    n = s.size();
    cin >> k;
    if (k == 1) {
        cout << s << endl;
        return 0;
    }

    buildSA();
    buildLCP();

    int res = -1;
    int len = 0;

    set<int> st;

    for (int i = 0; i <= k - 2; i++) {
        st.insert(lcp[i]);
    }
    int m = *st.begin();
    if (m > len) {
        res = 0;
        len = m;
    }
    
    for (int i = 1; i + k - 1 < n; i++) {
        st.erase(lcp[i - 1]);
        st.insert(lcp[i + k - 2]);
        int m = *st.begin();
        if (m > len) {
            res = i;
            len = m;
        }
    }

    if (res == -1) {
        cout << -1 << endl;
    } else {
        cout << s.substr(sa[res], len) << endl;
    }
    return 0;
}
