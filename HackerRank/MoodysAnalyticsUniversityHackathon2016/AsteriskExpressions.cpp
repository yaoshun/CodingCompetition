#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000007LL

ll power(ll y, ll x) {
  ll res = 1;
  y = y % INF;
  while (x > 0) {
    if (x % 2 == 1) {
      res = res * y % INF;
    }
    x = x / 2;
    y = y * y % INF;
  }
  return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string input;
        cin >> input;
        bool num = false;
        bool valid = true;
        string prepro;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '*') {
                if (!num) {valid = false; break;}
                if (i + 1 < input.size() && input[i + 1] == '*') {
                    prepro.push_back('*');
                    i++;
                    if (i + 1 < input.size() && input[i + 1] == '*') {valid = false; break;}
                } else {
                    prepro.push_back('+');
                }
                num = false;
            } else {
                num = true;
                prepro.push_back(input[i]);
            }
        }
        
        if (!num || !valid) {
            cout << "Syntax Error" << endl;
        } else {
            stack<char> operators;
            stack<ll> operands;
            for (int i = 0; i < prepro.size(); i++) {
                if (prepro[i] == '+') {
                    operators.push('+');
                } else if (prepro[i] == '*') {
                    operators.push('*');
                } else {
                    ll temp = prepro[i] - '0';
                    while (i + 1 < prepro.size() && isdigit(prepro[i + 1])) {
                        i++;
                        temp = temp * 10 + (prepro[i] - '0');
                    }
                    if (operators.empty()) {
                        operands.push(temp);
                    } else if (operators.top() == '*') {
                        operators.pop();
                        ll a = operands.top();
                        operands.pop();
                        ll res = power(a, temp);
                        operands.push(res);
                    } else {
                        operands.push(temp);
                    }
                }
            }
            
            ll res = 1;
            while (!operands.empty()) {
                res = res * (operands.top() % INF) % INF;
                operands.pop();
            }
            cout << res << endl;
        }
    }
    return 0;
}
