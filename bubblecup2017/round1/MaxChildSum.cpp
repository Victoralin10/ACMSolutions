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
#define MAXN 2000005

using namespace std;

int cnt = 1;
int V[MAXN], P[MAXN];
ll M[MAXN], S[MAXN];


int main(int nargs, char **args) {
    V[1] = 0, P[1] = -1, M[1] = 0, S[1] = 0;

    int q, t, x, y;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &t, &x);
        if (t == 1) {
            scanf("%d", &y);
            cnt++;
            V[cnt] = y;
            P[cnt] = x;
            M[cnt] = 0;

            int cn = cnt;
            while (cn > 0) {
                S[cn] += y;
                if (P[cn] > 0) {
                    M[P[cn]] = max(M[P[cn]], S[cn]);
                }
                cn = P[cn];
            }
        } else {
            cout << M[x] << endl;
        }
    }

    return 0;
}
