#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  queue<int> q;
  priority_queue<int> pq;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    q.push(x);
    pq.push(x);
  }

  int time = 0;
  while (m--) {
    if (q.front() == pq.top()) {
      q.pop();
      pq.pop();
      time += 2;
    } else {
      q.push(q.front());
      q.pop();
    }
  }

  while (q.front() != pq.top()) {
    m = q.size() - 1;
    q.push(q.front());
    q.pop();

    while (m--) {
      if (q.front() == pq.top()) {
        q.pop();
        pq.pop();
        time += 2;
      } else {
        q.push(q.front());
        q.pop();
      }
    }
  }

  cout << (time + 2) << endl;
  return 0;
}
