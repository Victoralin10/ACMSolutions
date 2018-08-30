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
    ll n;
    cin >> n;
    if (n == 1) {
        puts("-1");
    } else {
        cout << n << " " << n + 1 << " " << n*(n + 1) << endl;
    }

    return 0;
}
