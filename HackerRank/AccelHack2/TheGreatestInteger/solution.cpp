#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// There cannot be any negative integers which will generate
// infinite set. Zero doesn't affect the set as well.

// If we know the gcd of all the numbers and also the maximum number.
// there is a way to construct the basic gcd.

// Once we constructed the gcd, we can construct all the other numbers
// from the maximum number.
int gcd(int m, int n) {
    while (n != 0) {
        int t = n;
        n = m % n;
        m = t;
    }
    return m;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int m;
    cin >> m;
    
    int sub = nums[0];
    int maxi = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > maxi) {
            maxi = nums[i];
        }
        sub = gcd(sub, nums[i]);
    }
    
    cout << maxi - (m - 1) * sub << endl;
    
    return 0;
}

