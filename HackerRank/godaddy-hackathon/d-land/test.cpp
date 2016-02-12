#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const pair<long, pair<long, long>>& a, pair<long, pair<long, long>>& b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second.first < b.second.first;
    }
}

void push(vector<pair<long, long>>& res, vector<pair<long, pair<long, long>>>& arr, int i) {
    // binary search and insert.
    if (res.empty() || res.back().first > arr[i].second.first) {
        res.push_back({arr[i].second.first, arr[i].second.second});
        return;
    } else {
        int st = 0;
        int ed = res.size() - 1;
        while (st < ed) {
            int mid = st + (ed - st) / 2;
            if (res[mid].first > arr[i].second.first) {
                st = mid + 1;
            } else {
                ed = mid;
            }
        }
        
        long val = res[st].second + arr[i].second.second;
        res.insert(res.begin() + st, pair<long, long>{arr[i].second.first, val});
        while (st + 1 < res.size() && res[st + 1].first == arr[i].second.first) {
            res.erase(res.begin() + st + 1);
        }
        
        while (st - 1 >= 0 && res[st - 1].second <= val) {
            res.erase(res.begin() + st - 1);
            st--;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    
    vector<pair<long, pair<long, long>>> arr;
    for (int i = 0; i < n; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        arr.push_back({x, {y, w}});
    }
    sort(arr.begin(), arr.end(), cmp);

    vector<pair<long, long>> res;
    
    for (int i = 0; i < n; i++) {
        push(res, arr, i);
    }
    
    cout << res[0].second;
    
    return 0;
}
