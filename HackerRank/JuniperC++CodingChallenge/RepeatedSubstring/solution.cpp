#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100001

// All arrays are zero by default.
int sa[MAX], pos[MAX], tmp[MAX], lcp[MAX];
int st[2*MAX];

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

// Using array to implement complete binary tree.
// build of a segment tree-similar structure.
// binary search similar.
// the lowest level of the complete binary tree has n nodes. 
// Therefore at most it has 2*n nodes.
// with the array st, we can efficiently find the minimum of a given range.
// in the lcp array.
void build(int s, int e, int c) {
    if (s == e) {
        st[c] = lcp[s];
    } else {
        int m = (s + e) / 2;
        build(s, m, 2 * c + 1);
        build(m + 1, e, 2 * c +2);
        st[c] = min(st[2*c + 1], st[2*c + 2]);
    }
}

// c is the index to help find the segment tree.
// it follows the index of segment [s, e].
int fin(int s, int e, int c, int l, int r) {
    if (s == l && e == r) {
        return st[c];
    }
    int m = (s + e) / 2;
    if (r <= m) {
        return fin(s, m, 2 * c + 1, l, r);
    }
    if (l > m) {
        return fin(m + 1, e, 2 * c + 2, l, r);
    }
    return min(fin(s, m, 2 * c + 1, l, m), fin(m + 1, e, 2 * c + 2, m + 1, r));
}

int main() {
    cin >> s;
    n = s.size();
    cin >> k;

    buildSA();
    buildLCP();
    build(0, n - 1, 0);

    int res = -1;
    int len = 0;

    for (int i = 0; i + k - 1 < n; i++) {
        // the range of k - 1 of the lcp array is all bigger than a certain number.
        // that number is the length of the result maximum string.
        // scan the minimum of a windows with length k - 1.
        int m = fin(0, n - 1, 0, i, i + k - 2);
        if (m > len) {
            res = i;
            len = m;
        }
    }

    if (res == -1) {
        cout << -1 << endl;
    } else {
        for (int i = sa[res]; i < sa[res] + len; i++) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}
