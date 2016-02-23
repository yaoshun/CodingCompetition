#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // We couldn't remove and check because it will O(n^2) out the current limit.
    // We should check the current string and find the first condidate and check.
    // This is a typical heuristic algorithms.
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int i = 0;
        int j = s.size() - 1;
        while (i < j && s[i] == s[j]) {
            i++;
            j--;
        }
        if (i >= j) {
            cout << -1 << endl;
        } else {
            // check index i and j.
            int st = i + 1;
            int ed = j;
            while (st < ed && s[st] == s[ed]) {
                st++;
                ed--;
            }
            if (st >= ed) {
                cout << i << endl;
                continue;
            } else {
                // j must be a index, otherwise there is no solution.
                cout << j << endl;
            }
        }
    }
    return 0;
}

