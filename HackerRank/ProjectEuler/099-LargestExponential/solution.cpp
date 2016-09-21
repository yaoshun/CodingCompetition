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
    vector<pair<double, pair<int, int>>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].second.first;
        cin >> arr[i].second.second;
        arr[i].first = (double)arr[i].second.second * log((double)arr[i].second.first);
    }
    sort(arr.begin(), arr.end());
    int k;
    cin >> k;
    
    cout << arr[k-1].second.first << " " << arr[k-1].second.second << endl;
    return 0;
}
