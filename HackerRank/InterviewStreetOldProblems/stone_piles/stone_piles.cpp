#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> sg(51, 0);

void dfs(int start, int rest, int result, set<int> &st) {
    if (rest == 0) {
        st.insert(result);
    } else {
        for (int i = start + 1; i <= rest; i++) {
            dfs(i, rest - i, result ^ sg[i], st);
        }
    }
}

int main() {
    for (int i = 3; i <= 50; i++) {
        set<int> st;
        for (int j = 1; j < i; j++) {
            dfs(j, i - j, sg[j], st);
        }
        for (int j = 0; st.find(j) != st.end(); ) {
            j++;
            sg[i] = j;
        }
    }

    int T; 
    cin >> T;
    while (T--) {
        int n, res = 0;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            res ^= sg[x];
        }

        if (res) {
            cout << "ALICE" << endl;
        } else {
            cout << "BOB" << endl;
        }
    }
    return 0;
}

