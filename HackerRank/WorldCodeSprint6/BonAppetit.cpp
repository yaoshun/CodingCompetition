#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    cin >> n >> k;
    vector<ll> nums(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (i != k) sum += nums[i];
    }
    
    ll paid;
    cin >> paid;
    if (paid == sum / 2) {
        cout << "Bon Appetit" << endl;
    } else {
        cout << (paid - sum / 2) << endl;
    }
    return 0;
}
