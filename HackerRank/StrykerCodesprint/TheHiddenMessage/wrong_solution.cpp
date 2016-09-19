#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Failed a 3 test cases.
// The case fails in second part of not calculating the min cost.
// The min cost is independent of the first question.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string t;
    cin >> t;
    vector<string> p;
    string temp;
    vector<size_t> pos;
    bool res = true;
    int cost = 0;
    int cur = 0;
    while (cin >> temp) {
        size_t x = t.find(temp, cur);
        if (x != string::npos) {
            int diff = x - (p.empty() ? 0 : (cur + p.back().size()));
            cost += abs(diff);
            pos.push_back(x);
            p.push_back(temp);
            cur = x;
        } else {
            res = false;
            break;
        }
    }
    
    if (!p.empty()) {
        cost += t.size() - (cur + p.back().size());
        cost += p.size() - 1;
    }
    
    if (res) {
        cout << "YES" << endl;
        for (int i = 0; i < p.size(); i++) {
            if (i != 0) cout << " ";
            cout << p[i] << " " << pos[i] << " " << (pos[i] + p[i].size() - 1);
        }
        cout << endl;
        cout << cost << endl;
    } else {
        cout << "NO" << endl;
        if (p.empty()) {
            cout << 0 << endl;
        } else {
            for (int i = 0; i < p.size(); i++) {
                if (i != 0) cout << " ";
                cout << p[i] << " " << pos[i] << " " << (pos[i] + p[i].size() - 1);
            }
            cout << endl;
        }
        cout << 0 << endl;
    }
    
    return 0;
}

