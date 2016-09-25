// Here list the way to use customized priority queue.
#include <queue>
#include <functional>
auto cmp = [](const pair<int, ll>& a, const pair<int, ll>&b) {
    if (a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second > b.second;
    }
};

priority_queue<pair<int, ll>, vector<pair<int, ll>>, decltype(cmp)> pq(cmp);
