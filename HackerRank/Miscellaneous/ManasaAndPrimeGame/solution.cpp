#include <iostream>
#include <vector>
using namespace std;

// This is a typical nim game. 
// The key is to quickly calculate the nim number of all the independent piles.

// Fact 1:
// since each state can at most transfer to 6 other states, the maximum possible mex number if 6.
// Fact 2:
// It is very possible to be periodic, we can just brute force test it.
// 0 can reach nowhere: 0
// 1 can reach nowhere: 0
// 2 can reach 0: 1
// 3 can reach 0 and 1: 1
// 4 can reach 1 and 2: 2
// 5 can reach 0, 2 and 3: 2
// 6 can reach 1, 3 and 4: 3
// 7 can reach 0, 2, 4 and 5: 3 
// 8 can reach 1, 3, 5 and 6: 4
// 9 can reach 2, 4, 6 and 7: 0
// 10 can reach 3, 5, 7 and 8: 0
// 11 can reach 0, 4, 6, 8 and 9: 1
// 12 can reach 1, 5, 7, 9 and 10: 1
// Fact 3: 
// we found that 9 is the cycle.
typedef long long ll;
int nim[9] = {0,0,1,1,2,2,3,3,4};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            res ^= nim[temp % 9];
        }

        if (res == 0) {
            cout << "Sandy" << endl;
        } else {
            cout << "Manasa" << endl;
        }
    }
}
