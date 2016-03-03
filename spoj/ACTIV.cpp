/**
* Title:            ACTIV - Activities
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 100000000
#define MAXN 200005

using namespace std;

int B[MAXN];

void update(int px, int val) {
    while (px < MAXN) {
        B[px] += val;
        if (B[px] >= MOD) B[px] -= MOD;
        px += px&(-px);
    }
}

int query(int px) {
    int ans = 0;
    while (px) {
        ans += B[px];
        if (ans >= MOD) ans -= MOD;
        px -= px&(-px);
    }
    return ans;
}

pair <int, int> I[MAXN];

int main(int nargs, char **args) {
    //clock_t _inicio = clock();

    int n;
    while (scanf("%d", &n) != EOF) {
        if (n < 0) break;

        set <int> st;
        st.insert(0);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &I[i].second, &I[i].first);
            st.insert(I[i].first);
            st.insert(I[i].second);
        }

        map <int, int> mp;
        int id = 1;
        for (typeof st.begin() it = st.begin(); it != st.end(); it++) {
            mp[*it] = id++;
        }

        sort(I, I + n);

        memset(B, 0, sizeof B);
        update(mp[0], 1);

        for (int i = 0; i < n; i++) {
            int ns = query(mp[I[i].second]);
            update(mp[I[i].first], ns);
        }

        int ans = query(MAXN-1) - 1 + MOD;
        ans %= MOD;
        printf("%08d\n", ans);
    }

    //printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
