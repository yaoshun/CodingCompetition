#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        string s;
        cin >> s;
        int sum = 0;
        int res = 0;
        for (int j = 0; j < s.size(); j++) {
            if (sum < j) {
                res = max(res, j - sum);
            }
            sum += s[j]-'0';
        }
        cout << "Case #" << (i + 1) << ": " << res << endl;
    }    
    return 0;
}
