#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> t(n);
    for(int i = 0;i < n;i++){
       cin >> t[i];
    }
    
    // res represent the time point of the last entered person.
    int res = 0;
    
    for (int i = 0; i < n; i++) {
        if (t[i] <= res) {
            res++;
        } else {
            res = t[i];
        }
    }
    cout << res << endl;
    return 0;
}

