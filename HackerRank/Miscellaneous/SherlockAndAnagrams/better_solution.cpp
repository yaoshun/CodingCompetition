#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef long long unsigned llu;

// Calculate a hash from the frequency table.
// There is a slight chance that two different tables
// are different and have the same hash.
llu hashcal(vector<int>& freq) {
    llu t = 1;
    llu res = 0;
    for (int i = 0; i < 26; i++) {
        res += t * freq[i];
        t = t * (llu)1000003;
    }
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // The complexity here is more than O(n^3logn)
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        unordered_map<llu, int> mp;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; j++) {
                freq[s[j]-'a']++;
                mp[hashcal(freq)]++;
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

