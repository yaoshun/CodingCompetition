#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;


int main() {
    string s;
    cin >> s;

    // We use stack to achieve the property continuous reduction.
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }

    string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    if (res.empty()) {
        cout << "Empty String" << endl;
    } else {
        reverse(res.begin(), res.end());
        cout << res << endl;
    }

    return 0;
}
