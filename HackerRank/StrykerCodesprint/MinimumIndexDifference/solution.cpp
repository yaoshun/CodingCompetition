#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& A, const pair<int, int>& B) {
    return A.first < B.first;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<pair<int, int>> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i].first;
        B[i].second = i;
    }
    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    int res = A[0].first;
    int cur = abs(A[0].second - B[0].second);
    for (int i = 1; i < n; i++) {
        if (abs(A[i].second - B[i].second) < cur) {
            res = A[i].first;
            cur = abs(A[i].second - B[i].second);
        } else if (abs(A[i].second - B[i].second) == cur) {
            res = min(res, A[i].first);
        }
    }
    cout << res << endl;
    return 0;
}

