#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;
double A[1000];
double B[1000];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;

    for (int l = 0; l < T; l++) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }

        // A[n] is not considered in this case.
        sort(A, A + n);
        sort(B, B + n);
        // We calculate War first. 
        // Her opponent strategy is Straightfoward, using the one that just win.
        int i = 0;
        int j = 0;
        int res = 0;
        while (i < n && j < n) {
            if (A[i] < B[j]) {
                res++;
                j++;
                i++;
            } else {
                j++;
            }
        }
        int z = n - res;

        // We calculate Deceptive war second.
        // When Naomi want to win, she can play a small one and bluff it is MAX, making opponent play small ones.
        // When she want to lose, she can use a small one and claim a big one to make opponent plays a not-good one to win.
        i = 0; 
        j = 0;
        res = 0;
        while (i < n && j < n) {
            if (A[i] > B[j]) {
                res++;
                i++;
                j++;
            } else {
                i++;
            }
        }
        int y = res;

        cout << "Case #" << (l + 1) << ": " << y << " " << z << endl;
    }    
    return 0;
}
