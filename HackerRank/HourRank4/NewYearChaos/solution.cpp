#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 100001

int arr[MAX];
int org[MAX];
int pos[MAX];
int cnt[MAX];

int main(){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];

            // org[i] represents in the current status, 
            // what is the value at position i.
            // pos[i] represents in the current status,
            // what is the position of value i.
            // cnt[i] represents in the current status,
            // how many times has value i has bribed. 
            org[i] = i;
            pos[i] = i;
            cnt[i] = 0;
        }

        bool invalid = false;
        int res = 0;
        for (int i = n; i >= 1; i--) {
            if (invalid) {
                break;
            }

            // reversely deal with the array.
            // fix the last position first, then deal with previous position.
            // In this way, there would be no redundant moves.
            int oldp = pos[arr[i]];
            int newp = i;
            while (oldp != newp) {
                res++;
                cnt[org[oldp + 1]] += 1;
                if (cnt[org[oldp + 1]] > 2) {
                    invalid = true;
                    break;
                }
                swap(org[oldp], org[oldp + 1]);
                pos[org[oldp]] = oldp;
                pos[org[oldp + 1]] = oldp + 1;
                oldp++;
            }
        }

        if (invalid) {
            cout << "Too chaotic" << endl;
        } else {
            cout << res << endl;
        }
    }
    return 0;
}

