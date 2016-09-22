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

vector<pair<string, vector<int>>> arr;
unordered_map<string, int> mp;
unordered_set<string> open;

int main() {
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    string temp;
    cin >> temp;
    if (temp[0] == '^') {
      string s = temp.substr(1);
      if (open.find(s) == open.end()) {
        open.insert(s);
      }
      if (mp.find(s) == mp.end()) {
        arr.push_back(make_pair(s, vector<int>{}));
        mp[s] = arr.size() - 1;
      }
    } else if (temp[0] == '/') {
      string s = temp.substr(1);
      if (open.find(s) != open.end()) {
        open.erase(s);
      }
    } else {
      int num= stoi(temp);
      for (auto& s : open) {
        arr[mp[s]].second.push_back(num);
      }
    }
  }

  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++) {
    sort(arr[i].second.begin(), arr[i].second.end());
    cout << arr[i].first;
    for (int j = 0; j < arr[i].second.size(); j++) {
      cout << " " << arr[i].second[j];
    }
    cout << endl;
  }

  return 0;
}
