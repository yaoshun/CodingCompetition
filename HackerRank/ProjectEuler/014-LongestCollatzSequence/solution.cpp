#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// In this case it is OK to allocate 5000000 array.
// There is no stack size limit to it.
#define MAX 5000000 

vector<int> chain(MAX + 1, -1);
vector<int> nums(MAX + 1, -1);

// The key point is that temp might be out of range
// of integer.
int dp(long long x) {
    if (x <= MAX && chain[x] != -1) {
        return chain[x];
    }
    
    int res = 0;
    long long temp;
    if (x % 2 == 0) {
        temp = x / 2;
    } else {
        temp = 3*x + 1;
    }
    res++;
    
    res += dp(temp);

    if (x <= MAX) {
        chain[x] = res;
    }
    return res;
}

void preprocess() {
    chain[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        dp(i);
    }
    
    int res = 1;
    nums[res] = 1;
    for (int i = 1; i <= MAX; i++) {
        if (chain[i] >= chain[res]) {
            res = i;
        }
        nums[i] = res;
    }
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    preprocess();
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << nums[n] << endl;
    }
    return 0;
}

