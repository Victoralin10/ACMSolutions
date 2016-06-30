/**
* Title:            Robot Walk
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 250
#define MAXS 70000

using namespace std;

int G1[MAXN], G2[MAXN];
int cnt1 = 0, cnt2 = 0;
int s1, s2 = 0;
bool sel[MAXS];

int solve(int A[], int cnt, int sum) {
    memset(sel, false, sizeof sel);

    vector <int> st;
    vector <int>::iterator it;

    sort(A, A + cnt);
    for (int i = 0; i < cnt; i++) {
        vector <int> nvs;
        for (it = st.begin(); it != st.end(); it++) {
            int ns = (*it) + A[i];
            if (2*ns <= sum && !sel[ns]) {
                nvs.push_back(ns);
            }
        }

        for (it = nvs.begin(); it != nvs.end(); it++) {
            if (!sel[*it]) {
                st.push_back(*it);
                sel[*it] = true;
            }
        }
        if (2*A[i] <= sum) {
            if (!sel[A[i]]) {
                st.push_back(A[i]);
                sel[A[i]] = true;
            }
        }
    }

    int ans = (1<<30);
    for (it = st.begin(); it != st.end(); it++) {
        //cout << sum << " " << *it << endl;
        ans = min(ans, sum - 2*(*it));
    }

    return ans;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    int t, n;
    char dir[2];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        cnt1 = 0, cnt2 = 0;
        s1 = 0, s2 = 0;
        for (int i = 2*n; i >= 0; i--) {
            if ((i&1) == 0) {
                if (i%4 == 0) {
                    scanf("%d", &G1[cnt1]);
                    s1 += G1[cnt1];
                    cnt1++;
                } else {
                    scanf("%d", &G2[cnt2]);
                    s2 += G2[cnt2];
                    cnt2++;
                }
            } else {
                scanf("%s\n", dir);
            }
        }

        if (n < 3) {
            cout << "NO" << endl;
            continue;
        }

        int ans = solve(G1, cnt1, s1);
        ans += solve(G2, cnt2, s2);

        cout << ans << endl;
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
