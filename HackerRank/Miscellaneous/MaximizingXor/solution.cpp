#include <iostream>
#include <vector>
using namespace std;

int main() {
    int l;
    int r;
    cin >> l >> r;

    // The key to this problem is that
    // find the leftmost bit that l and r differ
    // therefore it must cover the following two number
    // 01111 and 10000, which contribute to the maximum xor
    // results.
    int x = l ^ r;
    int res = 1;
    while (x) {
        res = res << 1;
        x = x >> 1;
    }
    cout << (res - 1) << endl;
    return 0;
}
