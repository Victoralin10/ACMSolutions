/**
* Title:    6656 - Watching the Kangaroo
* Author:   Victor Cueva Llanos
* Email:    Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000000
#define MAXN 100005

using namespace std;

pair <int, int> P[MAXN];
pair <int, int> I[MAXN], I2[MAXN];

int sol_left(int n, int px) {
    if (px > I[n-1].second || px < I[0].first) {
        return 0;
    }
    if (px <= I[0].second) {
        return px - I[0].first;
    }

    int lo = 0, hi = n-1, med;
    while (hi - lo > 1) {
        med = (hi + lo)/2;
        if (I[med].second < px) {
            lo = med;
        } else {
            hi = med;
        }
    }

    return max(0, px - I[hi].first);
}

int sol_right(int n, int px) {
    if (px < I2[0].first || px > I2[n-1].second) {
        return 0;
    }
    if (px >= I2[n-1].first) {
        return I2[n-1].second - px;
    }

    int lo = 0, hi = n-1, med;
    while (hi - lo > 1) {
        med = (hi + lo)/2;
        if (I2[med].first <= px) {
            lo = med;
        } else {
            hi = med;
        }
    }

    return max(0, I2[lo].second - px);
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t, n, m;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &P[i].first, &P[i].second);
        }
        sort(P, P + n);

        // Eliminacion
        int j = 1;
        for (int i = 1; i < n; i++) {
            if (P[i].second > P[j-1].second) {
                P[j++] = P[i];
            }
        }
        n = j;

        for (int i = 0; i < n; i++) {
            I[i].first = P[i].first;
            I[i].second = (P[i].first + P[i].second)/2;
            I2[i].second = P[i].second;
            I2[i].first = (P[i].first + P[i].second + 1)/2;
        }

        int px, a1, a2;
        printf("Case %d:\n", caso);
        while (m--) {
            scanf("%d", &px);

            a1 = sol_left(n, px);
            a2 = sol_right(n, px);
            printf("%d\n", max(a1, a2));
        }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
