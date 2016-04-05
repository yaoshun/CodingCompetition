#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

/*
    This is a typical greedy search problem.
    Greedy algorithm, although simple during the implementation, often
    requires careful mathematical proof on the problem.
    Here the key question is to minimize the penalty, how should we align
    the jobs.

    Even we can switch through different tasks, it would be a better strategy to not switch the tasks.

    Consider the adjacent jobs i and j with D[i], M[i], D[j] and M[j],
    through easy deduction.
    The finishing time of i and j is 
    const + M[i] with deadline D[i] possible penalty const + M[i] - D[i]
    const + M[i] + M[j] with deadline D[j] possible penalty const + M[i] + M[j] - D[j]
    If we swap them, we have the penalty of 
    const + M[i] + M[j] - D[i] and const + M[j] - D[j]
    To reduce the maximum amount, put the higher deadline after is strictly  better than the other cases. 
*/

int main() {
    int T;
    cin >> T;
    vector<pair<int, int>> nums(T); 
    for (int i = 0; i < T; i++) {
        int x, y
        cin >> x >> y;
        nums[i].first = x;
        nums[i].second = y;
    }

    vector<pair<int, int>> ori = nums;
    sort(nums.begin(), nums.end());

    unordered_map<int, int> mp;
    mp[nums[0].first] = 0;
    int d = 0;
    for (int i = 1; i < T; i++) {
        if (nums[i].first != nums[i - 1].first) {
            d++;
            mp[nums[0].first] = d;
        }
    }

    // If we maintain a sorted list, we need to perform two 
    // regular operations as the time goes.

    for (int i = 0; i < T; i++) {
        // Find a place to insert D[i] and then
        // update all the after values with M[i] and
        // get the new maximum.
        // Segment tree can efficiently finish the job.
    }
}
