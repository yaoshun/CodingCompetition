#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    // List All the possible cycles. 
    // At least 3 nodes to form a cycle.
    // A -> C -> D : e + d + a
    // A -> B -> D : b + f + a 
    // A -> B -> C -> D : b + c + d + a
    // A B C not a cycle.
    // B C D not a cycle.
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    
    // As we can see, adding value to a is able to solve all
    // three edges.
    int res = 0;
    res = max(res, - e - d - a);
    res = max(res, - b - f - a);
    res = max(res, - c - b - d - a);
    cout << res << endl;
}

