#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(200, 0);
    
    // k represents the current highest bit count.
    int k = 0;
    arr[0] = 1;
    int carry = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            arr[j] = arr[j] * i + carry;
            carry = arr[j] / 10;
            arr[j] = arr[j] % 10;
        }
        while (carry) {
            k++;
            arr[k] = carry % 10;
            carry /= 10;
        }
    }
    
    for (int i = k; i >= 0; i--) {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}

