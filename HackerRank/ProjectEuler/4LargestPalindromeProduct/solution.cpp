nclude <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(int num) {
    // it is already 6 digit.
    int rev = 0;
    int temp = num;
    while (temp) {
        rev *= 10;
        rev += temp % 10;
        temp /= 10;
    }
    return rev == num;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    // cycle through 3 digit number is easier. 
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        
        int res = 0;
        for (int i = 100; i <= 999 && i * i < n; i++) {
            for (int j = i; j <= 999 && i * j < n; j++) {
                int temp = i * j;
                if (temp < n && isPalindrome(temp)) {
                    res = max(res, temp);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}

