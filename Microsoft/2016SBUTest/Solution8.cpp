#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;
class Solution {
public:
  static int ladderLength(string start, string end, unordered_set<string> &dict) {
    queue<string> q;
    // store length to visit a string.

    unordered_map<string, int> visited;

    for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();it++) {
      visited[*it]=-1;
    }

    visited[start]=0;
    // current level
    int level=0;

    // Push the orignal condition.
    q.push(start);

    while(!q.empty()) {
      while(!q.empty() && visited[q.front()]==level) {
        vector<string> temp=findDict(q.front(), dict);

        for(vector<string>::iterator it=temp.begin();it!=temp.end();it++) {
          // ending requirement
          if(end==(*it)) {
            // find the result;
            return (level+1);
          }

          if(visited[*it]==-1) {
            visited[*it]=level+1;
            q.push(*it);
          }
        }
        q.pop();

      }
      level++;
    }

    return -1;
  }

  static vector<string> findDict(string str, unordered_set<string>& dict) {
    vector<string> res;
    for(int i=0;i<str.size();i++) {
      string s=str;
      for(int j='a';j<='z';j++) {
        s[i]=j;

        if(dict.find(s)!=dict.end())
          res.push_back(s);

      }
    }
    return res;
  }
};

int main() {
  int n, q;
  cin >> n >> q;
  unordered_set<string> dict;
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    dict.insert(temp);
  }

  for (int i = 0; i < q; i++) {
    string A, B;
    cin >> A >> B;
    cout << Solution::ladderLength(A, B, dict) << endl;;
  }

  return 0;
}
