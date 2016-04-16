#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
typedef long long ll;
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] = nums[i] - 1;
    }
    
    vector<unordered_set<int>> loved(n);
    for (int i = 0; i < n; i++) {
        loved[nums[i]].insert(i);
    }
    
    int maxRes = 1;
    
    for (int i = 0; i < n; i++) {
        // Starting from one kid, we expand the circle.
        vector<int> res;
        unordered_set<int> st;
        res.push_back(i);
        st.insert(i);
        int left = i;
        int right = i;
        bool flag = true;
        int level = 0;
        while (true) {
            if (nums[nums[right]] == left) {
                // found a solution.
                res.push_back(nums[right]);
                st.insert(nums[right]);
                break;
            } else if (nums[nums[right]] == right) {
                int cur = nums[right];
                // dfs through cur with loved.
                st.insert(cur);
                queue<int> q;
                q.push(cur);
                while (!q.empty()) {
                    level++;
                    int t = q.size();
                    for (int j = 0; j < t; j++) {
                        int node = q.front();
                        q.pop();
                        for (auto nn : loved[node]) {
                            if (st.find(nn) == st.end()) {
                                st.insert(nn);
                                q.push(nn);
                            }
                        }
                    }
                }
                break;
            } else if (st.find(nums[right]) != st.end()) {
                flag = false;
                break;
            } else {
                res.push_back(nums[right]);
                st.insert(nums[right]);
                right = nums[right];
            }
        }
        
        if (flag) {
            maxRes = max(maxRes, (int)res.size() + level);
        }
    }
    
    cout << maxRes << endl;
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        cout << "Case #" << (t + 1) << ": ";
        solve();
    }    
    return 0;
}
