/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

using namespace std;

int find(string &s, int a, int b, char op) {
    int par = 0;
    for (int i = b; i >= a; i--) {
        if (s[i] == ')') par++;
        else if (s[i] == '(') par--;
        else if (par == 0 && s[i] == op) {
            return i;
        }
    }

    return -1;
}

double solve(string &s, int a, int b, double x) {
    int ind = find(s, a, b, '+');
    if (ind >= 0) {
        return solve(s, a, ind - 1, x) + solve(s, ind + 1, b, x);
    }

    ind = find(s, a, b, '-');
    if (ind >= 0) {
        return solve(s, a, ind - 1, x) - solve(s, ind + 1, b, x);
    }

    ind = find(s, a, b, '*');
    if (ind >= 0) {
        return solve(s, a, ind - 1, x)*solve(s, ind + 1, b, x);
    }

    if (s[a] == '(') {
        return solve(s, a + 1, b - 1, x);
    }

    if (s[a] == 'x') {
        return x;
    }

    int ans = 0;
    for (int i = a; i <= b; i++) {
        ans = ans*10 + (s[i] - '0');
    }
    return ans;
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();
    
    string line;
    int tc = 1;
    while (getline(cin, line)) {
        int l = line.size();
        int eq = find(line, 0, l - 1, '=');

        double xd1 = solve(line, 0, eq - 1, 3) - solve(line, eq + 1, l - 1, 3);
        double xd2 = solve(line, 0, eq - 1, 11) - solve(line, eq + 1, l - 1, 111);

        cerr << xd1 << " " << xd2 << endl;
        cout << "Equation #" << tc++ << endl;
        if (xd1 == xd2) {
            if (xd1 == 0) {
                cout << "Infinitely many solutions." << endl;
            } else {
                cout << "No solution." << endl;
            }
        } else {
            double lo = -(1<<25), hi = (1<<25), mid;
            while (lo - hi > 1e-7) {
                mid = lo + hi;
                double xd3 = solve(line, 0, eq - 1, mid) - solve(line, eq + 1, l - 1, mid);
                if (xd1 < xd2) {
                    if (xd3 < 0) lo = mid;
                    else hi = mid;
                } else {
                    if (xd3 < 0) hi = mid;
                    else lo = mid;
                }
            }
            
            printf("x = %.6f\n", lo);
        }
        cout << endl;
    }

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
