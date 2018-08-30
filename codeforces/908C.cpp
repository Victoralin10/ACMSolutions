#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double

#define MOD 1000000007
#define MAXN 1003
#define EPS 1e-9

using namespace std;


double y[MAXN], x[MAXN];

int main(int nargs, char **args) {
    double n, r, xi, yi, r2;
    cin >> n >> r;
    r2 = 4*r*r;
    for (int i = 0; i < n; i++) {
        cin >> xi;
        yi = r;

        for (int j = 0; j < i; j++) {
            double dr = abs(xi - x[j]);
            if (dr < 2*r + EPS) {
                yi = max(yi, y[j] + sqrt(r2 - dr*dr));
            }
        }

        x[i] = xi, y[i] = yi;
        printf("%.10f ", yi);
    }
    return 0;
}
