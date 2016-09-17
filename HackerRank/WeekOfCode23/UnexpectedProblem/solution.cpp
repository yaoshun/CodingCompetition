#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

void KMPlps(const string& s, vector<int>& lps) {
    int len = 0;
    int n = s.size();
    
    int i;
    lps[0] = 0;
    
    i = 1;
    while (i < n) {
        if (s[i] == s[len]) {
            lps[i] = len + 1;
            len++;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    int n = s.size();
    vector<int> lps(n, 0);
    KMPlps(s, lps);
    
    int unit = n;
    
    int x = lps[n - 1];
    if (n % (n - x) == 0) {
        unit = n - x;
    }
    
    ll m;
    cin >> m;
    
    cout << m / unit % 1000000007 << endl;
    
    return 0;
}
