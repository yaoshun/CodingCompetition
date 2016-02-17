#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;

    for (int l = 0; l < T; l++) {
        double C, F, X;
        cin >> C >> F >> X;

        double V = 2.0;
        if (X <= C) {
            cout << "Case #" << (l + 1) << ": " << X/V << endl;
            continue;
        }
        
        double res = 0;
        res += C/V; 
        // Check if did not spend the farm, the time needed to reach X is
        // (X - C) / V. if (X-C) /V * (V + F) > X, we should spend on the farm
        while ((X-C)/V > X/(V + F)) {
            V += F;
            res += C/V;
        }

        res += (X - C)/V;
        cout << fixed;
        cout << setprecision(7);
        cout << "Case #" << (l + 1) << ": " << res << endl;
    }    
    return 0;
}
