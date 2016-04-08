#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string res;
    int xorsum = 0;
    for (int i = 0; i < n; i++) {
        int digit = xorsum ^ (s[i] - '0');
        res.push_back('0' + digit);
        xorsum ^= digit;
        if (i >= k - 1) {
            xorsum ^= res[i - k + 1] - '0';
        }
    }
    cout << res << endl;
    return 0;
}

