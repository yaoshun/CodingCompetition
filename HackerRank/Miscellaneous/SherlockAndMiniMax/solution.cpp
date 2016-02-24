#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int p, q;
    cin >> p >> q;
    
    sort(nums.begin(), nums.end());
    // What is the possible answer of the problem?
    // p and q is possible. also the middle point of A[i], A[i + 1] is possible.
    // Check p and q.
    int resp = abs(p - nums[0]);
    int resq = abs(q - nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        resp = min(resp, abs(p - nums[i]));
        resq = min(resq, abs(q - nums[i]));
    }
    int res = resp < resq ? q : p;
    int resval = max(resp, resq);
    
    for (int i = 0; i < nums.size() - 1; i++) {
        // Even the difference is a odd number, there are two possbile solutions.
        // with the same min value. it is not possible that one is inside (p, q)
        // and the other one is outside [p, q]. Therefore we only need to consider
        // one of them. 
        int mid = nums[i] + (nums[i + 1] - nums[i])/2;
        if (mid > p && mid < q && (mid - nums[i]) > resval) {
            resval = mid - nums[i];
            res = mid;
        }
    }
    cout << res << endl;
    return 0;
}

