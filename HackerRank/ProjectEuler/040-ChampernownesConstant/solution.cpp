#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int findNthDigit(ll n) {
    // locate the number it is on.
    ll cur = 1;
    int digit = 1;
    while (n > 9 * cur * digit) {
        n -= 9 * cur * digit;
        cur *= 10;
        digit++;
    }
    
    // The nth digit starting from cur.
    // The n % digit's digit in num.
    ll num = cur + (n - 1) / digit;
    for (int i = 0; i < digit - 1 - (n - 1) % digit; i++) {
        num /= 10;
    }
    return num % 10;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        int res = 1;
        ll temp;
        for (int i = 0; i < 7; i++) {
            cin >> temp;
            res *= findNthDigit(temp);
        }
        cout << res << endl;
    }
    return 0;
}
