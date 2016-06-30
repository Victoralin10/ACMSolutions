/**
* Title:            3009 - Monks
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 501

using namespace std;

int D[MAXN][MAXN];
int F[] = {1, 2, 2};
int T[] = {0, 0, 1};

int solve(int a, int b, int c) {
    memset(D, -1, sizeof D);

    int N[] = {a, b, c}, suma = a + b + c;
    sort(N, N + 3);

    if (N[0] == 0) return 0;

    queue <pair <int, int> > Q;
    Q.push(make_pair(N[0], N[1]));
    D[N[0]][N[1]] = 0;

    while (!Q.empty()) {
        pair <int, int> q = Q.front();
        Q.pop();

        int A[] = {q.first, q.second, suma - q.first - q.second};

        sort(A, A + 3);
        for (int i = 0, B[3]; i < 3; i++) {
            memcpy(B, A, 12);
            B[F[i]] -= B[T[i]];
            B[T[i]] *= 2;

            sort(B, B + 3);

            if (B[0] == 0) return D[q.first][q.second] + 1;

            if (D[B[0]][B[1]] == -1) {
                D[B[0]][B[1]] = D[q.first][q.second] + 1;
                Q.push(make_pair(B[0], B[1]));
            }
        }
    }

    return -1;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    
    int a,b, c, d;
    while (cin >> a >> b >> c) {
        if (a + b + c == 0) break;
        d = solve(a, b, c);
        printf("%d %d %d %d\n", a, b, c, d);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
