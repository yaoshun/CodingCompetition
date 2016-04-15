#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

void solve() { 
    int K,L,S;
    cin >> K >> L >> S;
    string keys, target;
    cin >> keys >> target;

    // We need to calculate two things, at most pay. 
    // the second is the average pay. 
    // for at most pay, we calculate the maximum overlap between
    // inside the target.
    int O = 0;
    for (int i = 1; i < L; i++) {
        bool flag = true;
        for (int j = 0; j < i; j++) {
            if (target[j] != target[j + L - i]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            O = i;
        }
    }

    // After the calculation, we converted it to double.
    double max_copies = 1 + (S - L) / (L - O);

    // Expected copies, each copy is an independent event therefore we can
    // calculate them independently at all the positions.
    unordered_map<char, int> mp;
    for (auto c : keys) {
        mp[c]++;
    }

    for (auto c : target) {
        if (mp.find(c) == mp.end()) {
            printf("%.6f\n", 0.0);
            //cout << 0.0 << endl;
            return;
        }
    }

    double expected = 0.0;
    double p = 1.0;
    for (int i = 0; i < L; i++) {
        p *= (double)mp[target[i]] / K;
    }
    expected += (S - L + 1) * p;
    
    printf("%.6f\n", max_copies - expected);
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": ";
        solve();
    }    
    return 0;
}
