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

bool isLucky(int t) {
    if (t%10 == 7) return 1;
    t = t/60;
    if (t%10 == 7) return 1;
    return 0;
}

int main(int nargs, char **args) {
    int x, h, m, y = 0, t;
    cin >> x >> h >> m;
    t = h*60 + m;
    while (!isLucky(t)) {
        y++;
        t -= x;
        if (t < 0) t += 24*60;
    }
    cout << y << endl;

    return 0;
}
