#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;
int A[200001];
const ll P = 1000000007;

class Inteval {
public:
    int start;
    int end;
    Inteval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

// Generate one intevals out of [i,j] that covers index k.
inline long long generateOneCover(int st, int ed, int k) {
    // Consider how many number at left, how many number at right.
    long long res = (ll)(k - st + 1) * (ll)(ed - k + 1);
    return res % P;
}

inline long long generateOne(int st, int ed) {
    long long res = (ll)(ed - st + 2) * (ll)(ed - st + 1) / 2; 
    return res % P;
}

// Ways of Generate two intevals out of [i,j] that one of them covers index k.
long long generateTwo(int st, int ed, int k) {
    long long res = 0;
    for (int i = st; i < k; i++) {
        res += (i - st + 1) * generateOneCover(i + 1, ed, k) % P;
    }
    for (int i = k + 1; i <= ed; i++) {
        res += (ed - i + 1) * generateOneCover(st, i - 1, k) % P;
    }
    return res % P;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> B;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        B.push_back({A[i], i});
    }
    sort(B.begin(), B.end());

    // The algorithm calculates the minimum of all two non-empty nonoverlap intervals. 
    // Therefore, we can think at a reverse way.
    // From the smallest number calculate how many times, it will be used in such an interval pair.
    long long res = 0;
    vector<Inteval> q;
    q.push_back(Inteval(1, n));
    for (int i = 0; i < n; i++) {
        ll value = B[i].first;
        int ind = B[i].second;
        ll oneSum = 0;
        ll multiplier = 0;
        
        vector<Inteval> p;
        for (Inteval& r : q) {
            if (r.start <= ind && r.end >= ind) {
                res = (res + generateTwo(r.start, r.end, ind) * value) % P;
                multiplier = generateOneCover(r.start, r.end, ind);
                if (r.start < ind) {
                    p.push_back(Inteval(r.start, ind - 1));
                }
                if (r.end > ind) {
                    p.push_back(Inteval(ind + 1, r.end));
                }
            } else {
                oneSum = (oneSum + generateOne(r.start, r.end)) % P;
                p.push_back(r);
            }
        }
        q = p;
        res = (res + oneSum * multiplier %P * value % P) % P;
    }

    cout << res << endl;
}

