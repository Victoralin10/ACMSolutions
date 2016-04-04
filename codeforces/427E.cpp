/**
* Title:            427E. Police Patrol
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1000006

using namespace std;

int C[MAXN];
int n, m;

long long solve(int px) {
    long long ans = 0;
    for (int i = 0; i < n && C[i] <= px; i += m) {
        ans += px - C[i];
    }
    for (int i = n-1, c = 0; i >= 0 && C[i] >= px; i -= m) {
        ans += C[i] - px;
    }
    return 2*ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    long long lo = -MOD, hi = MOD, lom, him;
    while (hi - lo > 2) {
        lom = (2*lo + hi)/3;
        him = (lo + 2*hi)/3;
        if (solve(lom) > solve(him)) lo = lom;
        else hi = him;
    }
    // cout << lo << " " << hi << endl;
    // cout << solve(lo) << " " << solve(hi) << endl;
    long long ans = (1LL<<60);
    for (int i = lo; i <= hi; i++){
        ans = min(ans, solve(i));
    }
    cout << ans << endl;

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
