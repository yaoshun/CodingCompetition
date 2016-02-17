#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;

    vector<vector<int>> matrix(4, vector<int>(4));

    for (int i = 0; i < T; i++) {
        int first;
        cin >> first;

        vector<int> firstrow;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> matrix[j][k];
            }
        }

        for (int j = 0; j < 4; j++) {
            firstrow.push_back(matrix[first - 1][j]);
        }

        int second;
        cin >> second;
        vector<int> secondrow;

        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> matrix[j][k];
            }
        }
        
        for (int j = 0; j < 4; j++) {
            secondrow.push_back(matrix[second - 1][j]);
        }

        int cnt = 0;
        int res = 0;
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (firstrow[j] == secondrow[k]) {
                    cnt++;
                    res = firstrow[j];
                }
            }
        }

        if (cnt == 1) {
            cout << "Case #" << (i + 1) << ": " << res << endl;
        } else if (cnt > 1) {
            cout << "Case #" << (i + 1) << ": " << "Bad magician!" << endl;
        } else {
            cout << "Case #" << (i + 1) << ": " << "Volunteer cheated!" << endl;
        }
    }    
    return 0;
}
