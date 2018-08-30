/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 300005

using namespace std;

int X[MAXN];
vector <int> Px[MAXN];
int N[MAXN], P[MAXN];
int n, q;
int ans = 0, cnt = 1;

void del(int px) {
    if (P[px] >= 0) N[P[px]] = N[px];
    if (N[px] >= 0) P[N[px]] = P[px];
}

void init() {
    for (int i = 0; i <= q + 1; i++) {
        P[i] = i-1;
        N[i] = i+1;
    }
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock(); 
    cin >> n >> q;
    init();

    while (q--) {
        int tip, x;
        scanf("%d %d", &tip, &x);

        if (tip == 1) {
            X[cnt++] = x;
            Px[x].push_back(cnt - 1);
            ans++;
        } else if (tip == 2) {
            for (int i = 0;i < Px[x].size();i++) {
                if (X[Px[x][i]] > 0) {
                    del(Px[x][i]);
                    ans--;
                    X[Px[x][i]] = 0;
                }
            }
            Px[x].clear();
        } else {
            int cp = N[0];
            while (cp < cnt && cp <= x) {
                ans--;
                del(cp);
                X[cp] = 0;
                cp = N[cp];
            }
        }

        printf("%d\n", ans);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
