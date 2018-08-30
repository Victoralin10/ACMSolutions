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
    int k, a, b;
    cin >> k >> a >> b;
    if (a < b) {
        swap(a, b);
    }

    int ans = 0, op = b/k;

    ans += 2*op;
    a -= k*op;
    b -= k*op;

    int adi = a/k;
    a %= k;

    ans += adi;

    if (a > op*(k-1) || b > (op + adi)*(k-1)) {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}
