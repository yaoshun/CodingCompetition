#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, d;
    cin >>n >>d;
    if (n % 2 == 0) {
        cout << n / 2 + d << endl;
    } else {
        cout << n / 2 + d + 1 << endl;
    }
    return 0;
}
