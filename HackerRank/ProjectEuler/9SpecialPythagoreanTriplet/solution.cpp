nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Since T is on the scale of N, the key problem is to try to reduce the single test case to O(n).
    // move b^2 to the right we can get
    // c - b = a^2/(n-a)
    // c + b = n - a
    // we can solve c and b if there is a solution.
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int res = -1;
        for (int i = 1; i <= n / 3; i++) {
            if (i * i % (n - i) == 0 && (i * i / (n - i) + n - i) % 2 == 0) {
                int c = (i * i / (n - i) + n - i) / 2;
                int b = n - c - i;
                res = max(res, i*b*c);
            }
        }
        cout << res << endl;
    }
    return 0;
}

