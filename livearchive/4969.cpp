/**
* Title:            4969 - World of cubes
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 51

using namespace std;

int N, X, Y, Z;

struct Point {
    int x, y, z;
} P[MAXN], A[MAXN], B[MAXN];

int cnt, cnt2;

bool coverLine(double length) {
    if (cnt2 <= 0) return false;
    double x = 0;
    for (int i = 0; i < cnt2; i++) {
        if (B[i].x - length > x) {
            return false;
        }
        x = B[i].x + length;
    }
    return x >= X;
}

bool coverArea(double length) {
    if (cnt <= 0) return false;
    double y = 0, ny;
    while (y < Y) {
        cnt2 = 0; ny = (1<<30);
        for (int i = 0; i < cnt; i++) {
            if (A[i].y - length <= y && A[i].y + length > y) {
                B[cnt2++] = A[i];
                ny = min(ny, A[i].y + length);
            }
        }
        if (!coverLine(length)) {
            return false;
        }
        y = ny;
    }
    return true;
}

bool cover(unsigned int length) {
    double z = 0, nz, ml = length/2.0;
    while (z < Z) {
        cnt = 0;
        nz = (1<<30);
        for (int i = 0; i < N; i++) {
            if (P[i].z - ml <= z && P[i].z + ml > z) {
                A[cnt++] = P[i];
                nz = min(nz, P[i].z + ml);
            }
        }
        if (!coverArea(ml)) {
            return false;
        }
        z = nz;
    }

    return true;
}

bool cmp(Point a, Point b) {
    return a.x < b.x;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int caso = 1;
    while (scanf("%d%d%d%d", &N, &X, &Y, &Z) != EOF) {
        if ((long long) N + X + Y + Z <= 0) break;

        for (int i = 0; i < N; i++) {
            scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].z);
        }

        sort(P, P + N, cmp);

        unsigned int lo = 0, hi = (1<<31), mid;
        while (hi - lo > 1) {
            mid = (hi + lo)>>1;
            if (cover(mid)) hi = mid;
            else lo = mid;
        }

        printf("%d. %d\n", caso++, hi);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
