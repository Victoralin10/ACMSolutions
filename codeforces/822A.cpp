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
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    int ans = 1;
    for (int i = 2; i <= a; i++) {
        ans *= i;
    }
    cout << ans << endl;
    return 0;
}
