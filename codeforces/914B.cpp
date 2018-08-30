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
#define MAXN 100005

using namespace std;

int a[MAXN];

int main(int nargs, char **args) {
    int n;
    cin >> n;
    bool ok = 0;
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 1, cnt = 1;i <= n; i++) {
        if (a[i] != a[i-1]) {
            if ((cnt&1)) ok = 1;
            cnt = 1;
        } else {
            cnt++;
        }
    }
    puts(ok?"Conan":"Agasa");

    return 0;
}
