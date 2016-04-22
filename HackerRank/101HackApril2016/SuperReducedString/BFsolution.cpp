#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

// Notice the case of "baab", after reducing the "aa"
// "bb" can also be reduced, indicating a recursive algorithm.

int hasReduce(string s) {
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            return i;
        }
    }
    return -1;
}

int main() {
    string s;
    cin >> s;

    int cur = hasReduce(s);
    while (cur != -1) {
        s.erase(cur, 2);
        cur = hasReduce(s);
    }

    if (s.empty()) {
        cout << "Empty String" << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}
