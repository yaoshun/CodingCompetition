#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        // 9^7 is not very large, so it is ok to store
        // as int;
        int res = 0;
        int product = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                product *= (s[i] - '0');
                cnt++;
                if (cnt > k) {
                    product /= (s[i - k] - '0');
                    cnt--;
                    res = max(res, product);
                } else if (cnt == k) {
                    res = max(res, product);
                }
            } else {
                cnt = 0;
                product = 1;
            }
        }

        cout << res << endl;
    }
    return 0;
}

