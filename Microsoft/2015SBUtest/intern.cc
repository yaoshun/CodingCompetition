#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream infile ("PracticeInput.txt");
    int n;
    infile >> n;

    vector<int> dp(n, 0);
    vector<int> res(n, 0);
    vector<int> read(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            infile >> read[j];
        }
        
        res[0] = dp[0] + read[0];

        for (int j = 1; j <= i - 1; j++) {
            res[j] = max(dp[j - 1], dp[j]) + read[j];
        }

        res[i] = read[i] + dp[i - 1];
        dp = res;
    }
    int temp = dp[0];
    for (int i = 1; i < n; i++) {
        temp = max(temp, dp[i]);
    }
    cout << temp << endl;
    return 0;
}
