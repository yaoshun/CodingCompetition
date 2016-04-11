#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

// For the small dataset, LCM method is applicable, 
// since LCM is the periodicy of each problem.
int gcd(int a, int b) {
    int temp;
    if (b == 0) {
        return a;
    }
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int B, N;
        cin >> B >> N;
        vector<int> nums(B);
        for (int i = 0; i < B; i++) {
            cin >> nums[i];
        }

        int lcm = nums[0];
        for (int i = 1; i < B; i++) {
            // This way has lower chance to overflow.
            lcm = lcm / gcd(lcm, nums[i]) * nums[i];
        }

        int period = 0;
        for (int i = 0; i < B; i++) {
            period += lcm / nums[i];
        }

        N = (N - 1) % period;

        // Then we go through the simulation process.
        int res = 0;
        int customer = 0;
        for (int i = 0; ; i++) {
            // Catch each time point for the simulation process.
            for (int barber = 0; barber < B; barber++) {
                if (i % nums[barber] == 0) {
                    if (customer == N) {
                        res = barber + 1;
                        break;
                    }
                    customer++;
                }
            }
            if (res != 0) break;
        }
        
        cout << "Case #" << (t + 1) << ": " << res << endl;
    }    
    return 0;
}
