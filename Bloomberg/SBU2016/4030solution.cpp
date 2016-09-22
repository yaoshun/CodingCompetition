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

bool cmp(const pair<char, int>& a, const pair<char, int>& b) {
  return a.first > b.first;
}

int main() {
  string s;
  cin >> s;
  unordered_map<char, int> mp;
  for (char& c : s) {
    mp[c]++;
  }

  // 1. maximize digit is priority.
  // 2. only one odd number is allowed, pick the max.
  vector<pair<char, int>> arr;
  bool odd = false;
  char maxchar;
  for (auto& pair : mp) {
    arr.push_back(make_pair(pair.first, pair.second / 2));
    if (pair.second % 2 == 1) {
      if (!odd || pair.first > maxchar) {
        odd = true;
        maxchar = pair.first;
      }
    }
  }
  sort(arr.begin(), arr.end(), cmp);
  string res;
  for (auto& pair : arr) {
    res += string(pair.second, pair.first);
  }
  string temp = res;
  reverse(temp.begin(), temp.end());
  if (odd) {
    res += maxchar;
  }
  res += temp;
  cout << res << endl;
  return 0;
}
