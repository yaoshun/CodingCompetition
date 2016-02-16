#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;

unordered_map<char, int> mp = {{'i', 2}, {'j', 3}, {'k', 4}};
vector<vector<int>> M = {{0,0,0,0,0},
                         {0,1,2,3,4},
                         {0,2,-1,4,-3},
                         {0,3,-4,-1,2},
                         {0,4,3,-2,-1}};

int mul(int p, int q) {
    int sign = ((p > 0) == (q > 0)) ? 1 : -1;
    return sign * M[abs(p)][abs(q)];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // algorithm to answer yes or no.
    // Due to the associative law, we can make the following evaluations. 
    // 1) Evaluate total value to be equal to ijk, which is -1.
    // 2) Check whether there is a startup string that is i.
    // 3) Check wehther there is a end string that is k.
    // 4) For step 2) and 3) there should be a limit, if there is a cycle that s^D = 1.
    // Actually any expressio that string can reduce to. can have ^4 = 1;
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int L;
        ll X;
        cin >> L >> X;

        string s;
        cin >> s;

        // Check total value whether equal -1;
        int total = 1;
        for (int j = 0; j < L; j++) {
            total = mul(total, mp[s[j]]);
        }

        int res = 1;
        for (int j = 0; j < X%4; j++) {
            res = mul(res, total);
        }

        if (res != -1) {
            cout << "Case #" << (i + 1) << ": NO" << endl;
            continue;
        }

        // If total is -1, we can find "i" and "j", the "k" definitely exist.
        // find prefix can be equal to "i" and "j".
        // Cicular which means it can be done in 8 cycles. 
        int i_val = 1;
        int j_val = 1;
        for (int j = 0; j < min(X, (ll)8); j++) {
            for (int k = 0; k < L; k++) {
                if (i_val != 2) {
                    i_val = mul(i_val, mp[s[k]]);
                } else if (j_val != 3) {
                    j_val = mul(j_val, mp[s[k]]);
                }
            }
        }

        if (i_val == 2 && j_val == 3) {
            cout << "Case #" << (i + 1) << ": YES" << endl;
        } else {
            cout << "Case #" << (i + 1) << ": NO" << endl;
        }
    }    
    return 0;
}
