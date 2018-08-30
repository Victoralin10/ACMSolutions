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
    int n;
    while (cin >> n) {
        if (n == 0) break;

        int nd = 1;
        vector <int> exponentes;
        for (int i = 2; i*i <= n; i++) {
            int cnt = 0;
            while (n% i == 0) {
                cnt++;
                n /= i;
            }
            if (cnt) {
                exponentes.pb(cnt);
                nd *= cnt + 1;
            }
        }
        if (n > 1) {
            exponentes.pb(1);
            nd *= 2;
        }

        ll ans = 1;
        for (int i = 0; i < exponentes.size(); i++) {
            int x = exponentes[i];
            ans *= ((x*(x + 1))/2)*nd/(x + 1) + 1;
        }

        cout << ans << endl;
    }

    

    return 0;
}
