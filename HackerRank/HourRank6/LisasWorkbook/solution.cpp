#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cin >> n >> k;
    
    int res = 0;
    int cur = 1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        
        // Calculate the overlap between [cur, cur + (t - 1)/k] and [1, t]
        for (int j = 1; j <= t; j++) {
            if (cur + (j - 1)/k == j) {
                res++;
            }
        }
        cur = cur + (t - 1)/k + 1;
    }
    cout << res << endl;
    return 0;
}

