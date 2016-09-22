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

int R, C, M, N;

int main() {
  cin >> R >> C;
  vector<vector<int>> grid(R, vector<int>(C, 0));
  cin >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    grid[x][y] = 1;
  }
  cin >> N;
  vector<string> ops(N);
  for (int i = 0; i < N; i++) {
    cin >> ops[i];
  }

  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  int lastx = 0;
  int lasty = 0;
  int res;
  for (res = 0; res < ops.size(); res++) {
    int newx, newy;
    if (ops[res] == "R") {
      newx = lastx;
      newy = lasty + 1;
    } else if (ops[res] == "L") {
      newx = lastx;
      newy = lasty - 1;
    } else if (ops[res] == "U") {
      newx = lastx - 1;
      newy = lasty;
    } else if (ops[res] == "D") {
      newx = lastx + 1;
      newy = lasty;
    }

    if (newx < 0 || newx >= R && newy < 0 && newy > C) {
      break;
    }
    q.push(make_pair(newx, newy));
    lastx = newx;
    lasty = newy;

    if (grid[newx][newy] == 1) {
      grid[newx][newy] = 0;
    } else {
      q.pop();
    }

    pair<int, int> top = q.front();
    if (top.first == newx && top.second == newy) {
      break;
    }
  }

  if (res == ops.size()) {
    cout << -1 << endl;
  } else {
    cout << res + 1 << endl;
  }
  return 0;
}
