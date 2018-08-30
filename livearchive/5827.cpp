/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
const double PI = acos(-1);
#define EPS 1e-1

using namespace std;

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    string line;
    double X[3], Y[3];
    while (getline(cin, line)) {
        if (line == "END") break;

        stringstream io(line);
        io >> X[0] >> X[1];

        for (int i = 1; i < 3; i++) {
            cin >> X[i] >> Y[i];
        }

        double A[3], D[3];
        for (int i = 0; i < 3; i++) {
            double a1 = atan2(Y[i] - Y[(i + 1)%3], X[i] - X[(i + 1)%3]);
            double a2 = atan2(Y[i] - Y[(i + 2)%3], X[i] - X[(i + 2)%3]);
            if (a1 < 0) a1 += 2*PI;
            if (a2 < 0) a2 += 2*PI;

            A[i] = abs(a1 - a2)*180/PI;
            cout << A[i] << endl;
        }

        int ans = 3;
        for (; ans <= 1000; ans++) {
            double ai = 180.0 - 360/ans;

            for (int i = 0; i < 3; i++) {
                D[i] = abs(A[i]/ai - (int)(A[i]/ai + 0.5));
                // cout << D[i] << endl;
            }

            if (D[0] < EPS && D[1] < EPS && D[2] < EPS) {
                break;
            }
        }

        cout << ans << endl;
        getline(cin, line);
    }    

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
