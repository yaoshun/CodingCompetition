nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define MAX 1001
int A[MAX];
int B[MAX];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // Change one of B to maximize the "independent" one to one matching.
    int n;
    cin >> n;
    
    unordered_map<int, int> mpa, mpb;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        mpa[A[i]]++;
    }
    
    for (int i = 0; i < n ;i++) {
        cin >> B[i];
        mpb[B[i]]++;
    }
    
    int res = 0;
    for (auto pair : mpa) {
        int val = pair.first;
        if (mpb.find(val) != mpb.end()) {
            res += min(pair.second, mpb[val]);
        }
    }
    
    if (res < n) {
        res++;
    } else {
        // have to change one element and lose it.
        // When two arrays have completely the same structure.
        res--;
    }
    cout << res << endl;
    
    return 0;
}

