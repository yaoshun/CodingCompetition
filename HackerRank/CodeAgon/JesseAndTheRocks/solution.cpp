#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int strength;
    cin >> strength;
    int res = 0;
    bool skip = false;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp <= strength) {
            res++;
            continue;
        } else if (!skip) {
            skip = true;
            continue;
        } else {
            break;
        }
    }
    cout << res << endl;
    return 0;
}

