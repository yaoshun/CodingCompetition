#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    // A sucessfully change means the left side of the substring and the right side of the substring
    // hash sum could't exceed n/4.
    // Two pointer solution.
    
    int st = 0;
    int res = n;
    
    unordered_map<char, int> mp;
    
    // Find the first solution.
    while (st < n) {
        mp[s[st]]++;
        if (mp[s[st]] > n / 4) {
            mp[s[st]]--;
            st--;
            break;
        }
        st++;
    }
    
    if (st == n) {
        cout << 0 << endl;
        return 0;
    }
    
    res = min(res, n - st - 1);
    
    // two pointer solution.
    int ed = n - 1;
    while (st >= 0) {
        mp[s[st]]--;
        st--;
        while (ed >= 0) {
            mp[s[ed]]++;
            ed--;
            if (mp[s[ed + 1]] > n / 4) {
                ed++;
                mp[s[ed]]--;
                break;
            }
        }
        // the length between [st + 1, ed]
        res = min(res, ed - st);
    }
    
    cout << res << endl;
    
    return 0;
}

