/**
* Title:            D. Prefixes and Suffixes
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100005

using namespace std;

char s[MAXN];
int l, Z[MAXN];

void zalg() {
    l = strlen(s);

    Z[0] = l;

    int L, R;
    L = R = 0;
    for (int i = 1; i < l; i++) {
        if (i > R) {
            L = R = i;
            while (R < l && s[R - L] == s[R]) R++;
            Z[i] = R - L;
            R--;
        } else {
            if (i + Z[i - L] - 1 < R) Z[i] = Z[i - L];
            else {
                L = i;
                while (R < l && s[R] == s[R-L]) R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

int A[MAXN];

int get_count(int t) {
    if (t == A[0]) return l;

    int lo = 0, hi = l, mid;
    while (hi - lo > 1) {
        mid = (hi + lo)>>1;
        if (A[mid] < t) lo = mid;
        else hi = mid;
    }

    return l - hi;
}

int main(int nargs, char **args) {
    // clock_t _inicio = clock();

    scanf("%s", s);

    zalg();

    memcpy(A, Z, l*4);
    sort(A, A + l);

    vector <pair <int, int> > ans;
    for (int i = l-1; i >= 0; i--) {
        if (i + Z[i] == l) {
            ans.push_back(make_pair(Z[i], get_count(Z[i])));
        }
    }

    printf("%d\n", (int) ans.size());
    vector <pair<int, int> >::iterator it;
    for (it = ans.begin(); it != ans.end(); it++) {
        printf("%d %d\n", it->first, it->second);
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
