#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    
    int m = s.size();
    vector<int> arr(m + 1, 0);
    for (int i = 0; i < m; i++) {
        if (s[i] == 'a') {
            arr[i + 1] = arr[i] + 1;
        } else {
            arr[i + 1] = arr[i];
        }
    }
    
    long res = (n / m) * arr[m] + arr[n % m];
    cout << res << endl;
    return 0;
}

