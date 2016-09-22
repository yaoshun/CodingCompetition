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
typedef long long ll;

int N;

bool cmp(const pair<ll, int>& a, const pair<ll, int>& b) {
  if (a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}

int main() {
  cin >> N;
  vector<pair<ll, int>> arr;
  for (int i = 0; i < N; i++) {
    string t;
    cin >> t;
    // x and y will be the index of '|' in the string.
    int x = t.find('|');
    int y = t.find('|', x + 1);
    ll st = stoll(t.substr(x + 1, y));
    ll ed = stoll(t.substr(y + 1));
    arr.push_back(make_pair(st, 1));
    arr.push_back(make_pair(ed, -1));
  }
  sort(arr.begin(), arr.end(), cmp);

  int res = 0;
  int cur = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i].second == 1) {
      cur++;
    } else {
      cur--;
    }
    res = max(res, cur);
  }
  cout << res << endl;
  return 0;
}
