#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int factorial(int n) {
    if (n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    ifstream infile ("PracticeInput.txt");
    string s;
    while (infile >> s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        
        int odd_count = 0;

        for (unordered_map<char, int>::iterator iter = mp.begin(); iter!=mp.end(); iter++) {
            if ((iter->second) % 2 == 1) {
                odd_count++;
            }
        }

        if (odd_count > 1) {
            cout << (odd_count - 1) << ",";
        } else {
            cout << 0 << ",";
        }
        
        int n = (s.size() - odd_count)/2;
        int res = factorial(n);
        
        for (auto iter = mp.begin(); iter!=mp.end(); iter++) {
            int temp = iter->second / 2;
            res = res/factorial(temp);
        }
        cout << res << endl;
        mp.clear();
    }
    return 0;
}
