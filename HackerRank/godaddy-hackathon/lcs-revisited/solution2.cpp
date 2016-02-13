#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// To achieve a better performance than the naive O(n^3), we need to consider
// information of 1/N in the array. Each element has 1/N probability to appear.
// Also the size of the three strings are Ns.
// As a result, the possible Triplet that matches each other A[i] == B[j] == C[k]
// has a number of N.

// To deal with the problem, we construct the triplet and sort them by the x coordinates.

struct trip {
    // x, y, z store the coordinates in three strings.
    int x;
    int y;
    int z;
    int M;
};

bool cmp(const trip& a, const trip& b) {
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y < b.y;
    return a.z < b.z;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T > 0) {
        // Iterating throught the testcase
        T--;

        int n;
        cin >> n;
        vector<vector<int>> a(3, vector<int>(n));

        // Deal with the input.
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        // Solving the problem
        // First of all, efficiently find all the triplets.
        // v is actually a 3d array or 2d array of vector<int> type.
        //vector<int> v[n][3];
        vector<vector<vector<int>>> v(n, vector<vector<int>>(3));
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < n; j++) {
                // Generate a hashset for the positions of 
                // each char in three strings.
                v[a[i][j] - 1][i].push_back(j);
            }
        }

        // Build the triplets
        vector<trip> d;
        for (int i = 0; i < n; i++) {
            // For each possible value.
            for (int j = 0; j < v[i][0].size(); j++) {
                for (int k = 0; k < v[i][1].size(); k++) {
                    for (int l = 0; l < v[i][2].size(); l++) {
                        trip temp;
                        temp.x = v[i][0][j];
                        temp.y = v[i][1][k];
                        temp.z = v[i][2][l];
                        // A triplet corresponding to at least one lcs size.
                        temp.M = 1;
                        d.push_back(temp);
                    }
                }
            }
        }

        sort(d.begin(), d.end(), cmp);

        int res = 0;
        for (int i = 0; i < d.size(); i++) {
            // update the result from d[i] triplet.
            for (int j = 0; j < i; j++) {
                if (d[j].x < d[i].x && d[j].y < d[i].y && d[j].z < d[i].z) {
                    d[i].M = max(d[i].M, d[j].M + 1);
                }
            }
            res = max(res, d[i].M);
        }

        // Output the results
        cout << res << endl;
    }
    return 0;
}
