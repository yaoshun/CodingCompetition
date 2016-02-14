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
    cin >> n;
    // your code goes here
    if (n%3 == 2) {
        cout << (n/3 + 1) * (n/3 + 1) * (n/3) << endl;
    } else {
        cout << (n/3) * (n/3) * (n - n/3 - n/3) << endl;
    }
    return 0;
}

