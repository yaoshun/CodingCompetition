#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <iomanip>
using namespace std;

bool cmp(const tuple<int, double, double, double>& a,
         const tuple<int, double, double, double>& b) {
    return get<3>(a) > get<3>(b);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, b;
    cin >> n >> b;
    vector<tuple<int, double, double, double>> arr(n);
    for (int i = 0; i < n; i++) {
        int ind;
        double x, y, z;
        cin >> ind >> x >> y >> z;
        get<0>(arr[i]) = ind;
        get<1>(arr[i]) = x;
        get<2>(arr[i]) = y;
        get<3>(arr[i]) = z;
    }
    
    sort(arr.begin(), arr.end(), cmp);
    unordered_map<int, int> mp;
    for (int i = 0; i < b; i++) {
        mp[get<0>(arr[i])] = i;
    }
    
    int cur = b;
    string op;
    while (cin >> op) {
        int ind;
        cin >> ind;
        if (op == "F" || op == "f") {
            if (mp.count(ind)) {
                // cout << fixed << setprecision(3);
                // cout << ind << " = (" << get<1>(arr[mp[ind]])
                // << "," << get<2>(arr[mp[ind]])
                // << "," << get<3>(arr[mp[ind]]) << ")\n";
                printf("%d = (%.3f,%.3f,%.3f)\n", ind, get<1>(arr[mp[ind]]), get<2>(arr[mp[ind]]), get<3>(arr[mp[ind]]));
            } else {
                cout << "Point doesn't exist in the bucket. \n";
            }
        } else if (op == "R" || op == "r") {
            if (mp.count(ind)) {
                if (cur == n) {
                    cout << "No more points can be deleted. \n";
                } else {
                    mp.erase(ind);
                    cout << "Point id " << ind << " removed. \n";
                    mp[get<0>(arr[cur])] = cur;
                    cur++;
                }
            } else {
                cout << "Point doesn't exist in the bucket. \n";
            }
        }
    }
    
    return 0;
}
