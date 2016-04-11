#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // We calculate the minimum number of eaten mshrooms. 
        // First, no constant speed.
        int resone = 0;
        for (int i = 1; i < n; i++) {
            resone += (nums[i] < nums[i - 1])?(nums[i-1] - nums[i]):0;
        }

        // Secondly must constant speed.
        int speedtwo = 0;
        for (int i = 1; i < n; i++) {
            speedtwo = max(speedtwo, nums[i - 1] - nums[i]);
        }
        int restwo = 0;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > speedtwo) {
                restwo += speedtwo;
            } else {
                restwo += nums[i];
            }
        }
        cout << "Case #" << (t + 1) << ": " << resone << " " << restwo << endl;
    }    
    return 0;
}
