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

bool isSquare(int n) {
    if (n < 0) return false;
    int r = sqrt(n + 0.5);
    return n == r*r;
}


int main(int nargs, char **args) {
    int n, x, ans = -(1<<30);
    cin >> n;
    while (n--) {
        cin >> x;
        if (!isSquare(x)) {
            ans = max(ans, x);
        }
    }
    cout << ans << endl;

    return 0;
}
