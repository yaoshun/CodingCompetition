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
    int n;
    int k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> friends(k);
    bool res = false;
    for(int friends_i = 0;friends_i < k;friends_i++){
       cin >> friends[friends_i];
       if (s[friends[friends_i] - 1] == '0') {
           res = true;
       }
    }

    if (res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
