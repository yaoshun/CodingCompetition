#include <iostream>
#include <vector>
using namespace std;

int nums[1000000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // Find the nim sum of the nums array.
    int nimsum = 0;
    for (int i = 0; i < n; i++) {
        nimsum ^= nums[i];
    }

    if (nimsum == 0) {
        // The case that the first player cannot win.
        cout << 0 << endl;
    }

    int res = 0;
    // Find the number of nims that can be operated.
    for (int i = 0; i < n; i++) {
        // leftmost bit of the nimsum must be set to one
        // in nums[i].
        // change nums[i] to (nimsum^nums[i]) could be a possible solution.
        // since the original nimsum will ^(nimsum^nums[i])^nums[i] = 0.
        if ((nimsum ^ nums[i]) < nums[i]) {
            res++;
        }
    }
    cout << res << endl;
}
