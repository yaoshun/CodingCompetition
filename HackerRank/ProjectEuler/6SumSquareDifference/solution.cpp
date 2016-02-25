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
        long long n; 
        cin >> n;
        long long SqSum = n * (n + 1) * (2 * n + 1) / 6;
        long long SumSq = n * n * (n + 1) * (n + 1) / 4;
        cout << abs(SumSq - SqSum) << endl;
    }
    return 0;
}

