#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// The maximal area lies in a circle.

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> L(n);
    
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    
    double minlength = (double)L[0]/2;
    double maxlength = (double)L[0]/2;
    for (int i = 1; i < n; i++) {
        minlength = min(minlength, (double)L[i]/2);
        maxlength = max(maxlength, (double)L[i]/2);
    }
    
    double pi = 3.14159265359;
    double rmin = maxlength;
    double rmax = maxlength / sin(pi/n);
    
    // Binary search the value of R.
    // asin(L1/2r) + asin(L2/2r) +... = pi.
    
    while ((rmax - rmin) > 0.000000001) {
        double mid = rmin + (rmax - rmin) / 2;
        double angel = 0;
        for (int i = 0; i < n; i++) {
            angel += asin((double)L[i] / 2 / mid);
        }
        if (angel > pi) {
            rmin = mid;
        } else {
            rmax = mid;
        }
    }
    double r = rmin;
    
    // the centroid of circle is
    double centroid_y = (double)L[0]/2;
    double centroid_x = sqrt(r * r - centroid_y * centroid_y);
    
    // Calculate all the coordinates.
    vector<pair<double, double>> res;
    res.push_back({0, 0});
    res.push_back({0, (double)L[0]});
    double last_y = (double)L[0];
    double last_x = 0.0;
    
    for (int i = 1; i < n; i++) {
        double angle = asin((double)L[i]/2/r);
        angle = angle * 2;
        double cur_y = centroid_y + (last_y - centroid_y) * cos(angle) - (last_x - centroid_x) * sin(angle);
        double cur_x = centroid_x + (last_x - centroid_x) * cos(angle) + (last_y - centroid_y) * sin(angle);
        res.push_back({cur_x, cur_y});
        last_x = cur_x;
        last_y = cur_y;
    }
    
    for (int i = 0; i < n; i++) {
        cout << res[i].first << endl;
        cout << res[i].second << endl;
        cout << endl;
    }
    
    return 0;
}

