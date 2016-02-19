#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    string S;
    cin >> S;
    int res;
    for (int i = 0; i < S.size(); i += 3) {
        if (S[i] != 'S') {
            res++;
        }
        if (S[i+1] != 'O') {
            res++;
        }
        if (S[i+2] != 'S') {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}

