#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Have to read the problem carefully.
// The course will ends in some day that everyone danced in that day regardless of previous days.

// Calculate p_finish_today - the probablity that the classies will end in one day. 
// ev_finish_today - the expected number of dances, assuming it ends on one day.
// ev_start_agina - the exptected number of dances, assuming that some pari will get upset and we need to start again tomorrow.

#define MAX 31

double p[MAX][MAX][MAX*MAX], ev[MAX][MAX][MAX*MAX];
double p_finish_today, ev_finish_today;
double p_start_again, ev_start_again;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m;
    double r;
    cin >> n >> m >> r;

    p[0][0][0] = 1;

    // p[i][j][k] represents the probability to reach
    // i people and j people danced, together k pairs have danced.

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= i * j; k++) {
                double &my_p = p[i][j][k];
                double &my_ev = ev[i][j][k];

                if (i == n && j == m) {
                    p_finish_today += my_p;
                    ev_finish_today += my_ev;
                    continue;
                }

                double omega = n * m;
                double x;

                // Staying in the same place
                x = k * (1-r) / omega;
                // this is a convergence series.
                // x + x^2 + x^3 +...
                my_ev += 1/(1 - x) * my_p;
                // Next few cases are based on a new dance will change sth.
                omega -= k * (1-r);

                // Starting a new day
                x = k * r / omega;
                p_start_again += x * my_p;
                // my_ev - my_p = original my_ev + prev_x / (1- prev_x)
                ev_start_again += x * (my_ev - my_p);

                // new boy
                x = (n - i) * j / omega;
                p[i + 1][j][k + 1] += x * my_p;
                ev[i + 1][j][k + 1] += x * my_ev;

                // new girl
                x = i * (m - j) / omega;
                p[i][j + 1][k + 1] += x * my_p;
                ev[i][j + 1][k + 1] += x * my_ev;

                // new both
                x = (n - i) * (m - j) / omega;
                p[i + 1][j + 1][k + 1] += x * my_p;
                ev[i + 1][j + 1][k + 1] += x * my_ev;

                // new pair with visited boy and visited girl
                x = (i * j - k) / omega;
                p[i][j][k + 1] += x*my_p;
                ev[i][j][k + 1] += x * my_ev;
            }
        }
    }

    printf("%.10f\n", ev_finish_today / p_finish_today + ev_start_again / p_finish_today);

    return 0;
}

