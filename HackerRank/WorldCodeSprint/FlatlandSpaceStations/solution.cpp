#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0;c_i < m;c_i++){
       cin >> c[c_i];
    }
    
    // The second line is unordered and unique.
    int res = 0;
    sort(c.begin(), c.end());
    
    res = max(res, c[0] - 0);
    
    for (int i = 1; i < c.size(); i++) {
        res = max(res, (c[i] - c[i - 1])/2);
    }
    res = max(n - 1 - c.back(), res);
    cout << res << endl;
    return 0;
}

