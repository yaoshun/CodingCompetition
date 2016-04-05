#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

bool isSame(string s) {
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            return false;
        }
    }
    return true;
}

int stringReduction(string s) {   
    if (isSame(s)) {
        return s.size();
    } else {
        int cnt[3];
        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;
        }
        
        if ((cnt[0] % 2) == 0 && (cnt[1] % 2) == 0 && (cnt[2] % 2) == 0) {
            return 2;
        } else if ((cnt[0] % 2) == 1 && (cnt[1] % 2) == 1 && (cnt[2] % 2) == 1) {
            return 2;
        } else {
            return 1;
        }
    }
}

int main() {
    int res, t, i;
    cin >> t;
    string s;
    for (i = 0; i < t; i++) {
        cin >> s;
        res = stringReduction(s);
        cout << res << "\n";
    }
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

