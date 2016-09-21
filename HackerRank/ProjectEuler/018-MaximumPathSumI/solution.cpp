#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<ll>> arr(n, vector<ll>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> arr[i][j];
            }
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                arr[i][j] += max(arr[i + 1][j], arr[i + 1][j + 1]);
            }
        }
        
        cout << arr[0][0] << endl;
    }
    return 0;
}
