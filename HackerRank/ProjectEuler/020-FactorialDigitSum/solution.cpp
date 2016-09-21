#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> res(1001, 0);
vector<int> mult(vector<int> bignum, int x) {
    int digits = 0;
    int temp = x;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }
    
    vector<int> res(bignum.size() + digits, 0);
    
    for (int i = 0; i < bignum.size(); i++) {
        temp = bignum[i] * x;
        int j = i;
        int carry = 0;
        while (temp > 0) {
            res[j] += (temp % 10) + carry;
            if (res[j] >= 10) {
                res[j] -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            temp /= 10;
            j++;
        }
        if (carry == 1) {
            res[j]++;
        }
    }
    
    while (res.back() == 0) res.pop_back();
    
    return res;
}

void preprocess() {
    // 0! = 1, 1! = 1.
    res[0] = 1;
    res[1] = 1;
    vector<int> temp = {1};
    for (int i = 2; i <= 1000; i++) {
        temp = mult(temp, i);
        for (int j = 0; j < temp.size(); j++) {
            res[i] += temp[j];
        }
    }
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    preprocess();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << res[n] << endl;
    }
    return 0;
}
