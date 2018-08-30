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
    int n, a, s = 0;
    bool impar = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if ((a&1)) impar = 1;
        s += a;
    }
    if (!(s&1)) puts("0");
    else if (impar && n > 1) puts("1");
    else puts("-1");

    return 0;
}
