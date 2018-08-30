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
#define MAXN 10

using namespace std;


int main(int nargs, char **args) {
    long long g, t, a, d, x, y;
    while (cin >> g >> t >> a >> d) {
        if (g + t + a + d == -4) break;
        x = g*(t*(t-1))/2;
        y = g*a + d;
        int i = 0;
        while ((1L<<i) < y) i++;
        y = (1L<<i) - y;
        x += g*a + d + y - 1;
        printf("%lld*%lld/%lld+%lld=%lld+%lld\n", g, a, t, d, x, y);
    }
    return 0;
}
