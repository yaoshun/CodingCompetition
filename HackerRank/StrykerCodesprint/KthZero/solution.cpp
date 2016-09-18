#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100011
int A[100011];
int B[401];

// O(n*sqrt(n)) algorithm.
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] == 0) {
            B[i / 250]++;
        }
    }
    
    for (int i = 0; i < q; i++) {
        int query;
        cin >> query;
        if (query == 1) {
            int k;
            cin >> k;
            int psum = 0;
            for (int j = 0; j <= 400; j++) {
                if (psum + B[j] >= k) {
                    for (int m = j * 250; m < (j + 1) * 250 && m < n; m++) {
                        if (A[m] == 0) {
                            psum++;
                        }
                        if (psum == k) {
                            cout << m << endl;
                            break;
                        }  
                    }
                    break;
                }
                psum += B[j];
            }
            if (psum < k) {
                cout << "NO" << endl;
            }
            
        } else if (query == 2) {
            int p, x;
            cin >> p >> x;
            if (A[p] != 0 && x != 0) {
                A[p] = x;
            } else if (A[p] == 0 && x != 0){
                B[p/250]--;
                A[p] = x;
            } else if (A[p] != 0 && x == 0) {
                B[p/250]++;
                A[p] = x;
            } else {
                // do nothing here. 
            }
        }
    }
    
    return 0;
}

