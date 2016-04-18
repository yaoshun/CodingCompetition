#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Point {
    double x;
    double y;
    double z;
};
// With the limiting of N <= 100.
// Therefore the bruteforce O(N ^ 3) algorithm is OK to work.

double angle(Point& a, Point& b, Point& c) {
    // Due to the range is between 0 to pi.
    // arccos is a good choice.
    double x1 = a.x - b.x;
    double y1 = a.y - b.y;
    double z1 = a.z - b.z;
    double x2 = c.x - b.x;
    double y2 = c.y - b.y;
    double z2 = c.z - b.z;
    double cosval = (x1 * x2 + y1 * y2 + z1 * z2) / sqrt(x1 * x1 + y1 * y1 + z1 * z1) / sqrt(x2 * x2 + y2 * y2 + z2 * z2);
    return acos(cosval);
}

int main() {
    int N;
    cin >> N;
    vector<Point> arr(N);
    for (int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].x = (double)x;
        arr[i].y = (double)y;
        arr[i].z = (double)z;
    }

    // calculate the sum
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                count++;
                sum += angle(arr[i], arr[j], arr[k]);
            }
        }
    }
    double res = sum / (double)count;
    printf("%.11f\n", res);

    return 0;
}
