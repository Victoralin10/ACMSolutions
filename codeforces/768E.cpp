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
#define MAXN 61

using namespace std;


int main(int nargs, char **args) {
    int G[MAXN];
    for (int i = 0, v = 0, c = 1; i < MAXN; ) {
        for (int j = 0; j < c && i < MAXN; j++) {
            G[i++] = v;
        }
        c++, v++;
    }

    int n, s, ans = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &s);
        ans ^= G[s];
    }

    puts(ans==0?"YES":"NO");

    return 0;
}
