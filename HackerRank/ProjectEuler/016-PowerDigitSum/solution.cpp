#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10001
vector<int> res(MAX, 0);

string multTwo(string a) {
    reverse(a.begin(), a.end());
    int n = a.size();
    int carry = 0;
    string res;
    int i;
    for (i = 0; i < n; i++) {
        int t = (a[i] - '0') * 2 + carry;
        if (t >= 10) {
            carry = 1;
            t -= 10;
        } else {
            carry = 0;
        }
        res.push_back(t + '0');
    }

    if (carry > 0) {
        res.push_back(carry + '0');
    }
    reverse(res.begin(), res.end());
    return res;
}

void preprocessing() {
    string s("2");
    res[1] = 2;
    for (int i = 2; i < MAX; i++) {
        s = multTwo(s);
        for (int j = 0; j < s.size(); j++) {
            res[i] += s[j] - '0';
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    preprocessing();
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << res[n] << endl;
    }

    return 0;
}
