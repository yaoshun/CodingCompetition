#include <iostream>
#include <algorithm>

using namespace std;

// if n == 1 obivously Kitty wins
// Else the one plays the last move wins.
// consider the last two integer a and b.
// if (a == b or (a-b) % 3 == 0), the last player wins.
// if (a - b) % 3 == 2, he can do (b - a) to make the result 1.
// vice versa, so the last player wins.

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "Kitty" << endl;
        } else if (n % 2 == 0) {
            cout << "Kitty" << endl;
        } else {
            cout << "Katty" << endl;
        }
    }
    return 0;
}

