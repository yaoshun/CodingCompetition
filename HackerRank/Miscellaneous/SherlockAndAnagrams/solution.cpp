#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // The complexity here is more than O(n^3logn)
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        unordered_map<string, int> mp;
        for (int i = 1; i <= s.size() - 1; i++) {
            for (int j = 0; j + i - 1 < s.size(); j++) {
                string t = s.substr(j, i);
                sort(t.begin(), t.end());
                mp[t]++;
            }
        }

        int res = 0;
        for (auto pair : mp) {
            res += pair.second * (pair.second - 1) / 2;
        }
        cout << res << endl;
    }

    return 0;
}

