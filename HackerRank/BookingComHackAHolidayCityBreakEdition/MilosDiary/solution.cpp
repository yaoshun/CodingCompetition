#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

int main() {

    int m;
    cin >> m;
    vector<int> nums(m);

    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    bool res = true;
    stack<int> st;
    int visited = 0;
    for (int i = 0; i < m; i++) {
        if (nums[i] > visited) {
            while (nums[i] > visited) {
                visited++;
                st.push(visited);
            }
            st.pop();
        } else if (st.empty() || nums[i] != st.top()) {
            res = false;
            break;
        } else {
            st.pop();
        }
    }

    if (res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
