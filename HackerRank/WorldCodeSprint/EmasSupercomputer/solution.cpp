#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 16

char c[MAX][MAX];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
        }
    }

    int ans = 0;

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= m; y++) {
            // Expand it to a certain level,
            // since it is not necessary to expand it to max to get the max value.
            int r = 0;
            while (x + r <= n && x - r >= 1 && y + r <= m && y - r >= 1 && 
                c[x + r][y] == 'G' && c[x-r][y] == 'G' && c[x][y+r] == 'G' && c[x][y-r]=='G') {
                c[x + r][y] = c[x - r][y] = c[x][y+r] = c[x][y-r] = 'g';
                for (int X = 1; X <= n; X++) {
                    for (int Y = 1; Y <= m; Y++) {
                        int R = 0;
                        while (X + R <= n && X - R >= 1 && Y + R <= m && Y - R >= 1 &&
                            c[X + R][Y] == 'G' && c[X-R][Y]=='G' && c[X][Y+R]=='G' && c[X][Y-R]=='G') {
                            ans = max(ans, (1 + 4 * r) * (1 + 4 * R));
                            R++;
                        }
                    }
                }
                r++;
            }

            // Recover it.
            r=0;
            while (x + r <= n && x - r >= 1 && y + r <= m && y - r >= 1 &&
                c[x + r][y] == 'g' && c[x-r][y] == 'g' && c[x][y+r] == 'g' && c[x][y-r]=='g') {
                c[x + r][y] = c[x - r][y] = c[x][y+r] = c[x][y-r] = 'G';
                r++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
