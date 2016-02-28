#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int m = a.size();
    int n = b.size();
    int carry = 0;
    string res;
    int i;
    for (i = 0; i < min(m, n); i++) {
        int t = (a[i] - '0') + (b[i] - '0') + carry;
        if (t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res.push_back(t + '0');
    }
    while (i < m) {
        int t = (a[i] - '0') + carry;
        if (t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res.push_back(t + '0');
        i++;
    }

    while (i < n) {
        int t = (b[i] - '0') + carry;
        if (t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res.push_back(t + '0');
        i++;
    }
    if (carry > 0) {
        res.push_back(carry + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;

    string res = "0";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        res = add(res, s);
    }

    cout << res.substr(0, 10) << endl;

    return 0;
}
