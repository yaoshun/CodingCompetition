#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Notice the way of string initilization with copy of char.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s;
    cin >> s;
    int left = 0;
    int down = 0;
    for (char& c : s) {
        if (c == 'N') {
            down--;
        } else if (c == 'S') {
            down++;
        } else if (c == 'W') {
            left++;
        } else if (c == 'E') {
            left--;
        }
    }
    
    string res;
    
    if (down > 0) {
        res += string(down, 'S');
    } else if (down < 0) {
        res += string(-down, 'N');
    }
    
    if (left > 0) {
        res += string(left, 'W');
    } else if (left < 0) {
        res += string(-left,'E');
    }
    
    sort(res.begin(), res.end());
    cout << res << endl;
    return 0;
}

