#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int D;
        cin >> D;

        // Deal with input
        vector<int> nums;
        int temp;
        for (int j = 0; j < D; j++) {
            cin >> temp;
            nums.push_back(temp);
        }

        // Calculate minimum minutes.
        // There are two types of strategies: "move" and "eat".
        // Theory 1: "move" operation definitely move something into empty plates. 
        // Theory 2: "<eat, move>" is equal or worse than the same "<move, eat>", the optimal strategy takes the form of "move, move, move, eat, eat, eat".
        // Theory 3: Assuming the eating step length is X. The time to deal with existing ones are easy to know.
        int max_pancakes = *max_element(nums.begin(), nums.end());
        // No move at all case.
        int res = max_pancakes;
        for (int x = 1; x < max_pancakes; x++) {
            int total_moves = 0;
            for (int ele : nums) {
                total_moves += (ele - 1) / x;
            }
            total_moves += x;
            res = min(res, total_moves);
        }

        cout << "Case #" << (i + 1) << ": " << res << endl;
    }    
    return 0;
}
