#include <iostream>
#include <vector>
using namespace std;

// Although this is a nim game, however both 
// the end state and also the intermediate state are hard
// to calculate.
// Therefore we come to the second theory commonly used in
// combinatorial game theories: minimax theorem.
// minimax theorem with memorization (dp) is the key to solve this
// problem.
// 
// The idea of minimax theorem is simple. Assuming it is a zero-sum game.
// the best outcome of the remaining game.
// my current state is S, and I need to calculate the score f(S). 
// Consider all the possible states, T1, T2,...Tn that I can make a move from S, then I have
// f(S) = max(-f(T1), -f(T2), -f(T3),..., -f(Tn))
//      = -min(f(T1), f(T2), f(T3),..., f(Tn)).
// simply because my opponent will maximize his score.

// The possible number of states are 1 << 15 which is 32768 which is OK. 
// each state in a tree repesent the state containing the ith bit meaning the current
// array have the nums[i].
int tree[1 << 15];
int cache[1 << 15];
int nums[15];
int n;

// Only two outcomes, we can do it easier with 0 as loss and 1 as win.
int solve(int node) {
    if (tree[node] != -1) {
        return tree[node];
    } else {
        // mark it as losing position.
        tree[node] = 0;

        // iterate through all its children.
        for (int i = 0; i < n; i++) {
            // not a leaf node,
            if (node & (1 << i)) {
                if (solve(node - (1<<i)) == 0) {
                    tree[node] = 1;
                    break;
                }
            }
        }
        return tree[node];
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // Initialize the first cell in the tree and cache arrays.
        // this cell didn't contain any element in the tree.
        tree[0] = 0;
        cache[0] = 0;

        // Iterate through each number in the sequence, creating a binary tree
        // representing the outcome of deleting the current node in the sequence.
        for (int i = 0; i < n; i++) {
            int offset = 1 << i;

            for (int j = 0; j < offset; j++) {
                // this is ending position with an increasing array.
                if (tree[j] == 0 && nums[i] > cache[j]) {
                    tree[offset + j] = 0;
                } else {
                    // undefined condition.
                    tree[offset + j] = -1;
                }

                // in those states the last number is nums[j].
                // cache stores the last number in the array.
                cache[offset + j] = nums[i];
            }
        }

        // There is no intermediate results.
        // every number is contained at the begining.
        int alice_wins = solve((1 << n) - 1);
        if (alice_wins) {
            cout << "Alice" << endl;
        } else {
            cout << "Bob" << endl;
        }
    }
}

