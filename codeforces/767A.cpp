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

int n;
bool ok[MAXN];

int main(int nargs, char **args) {
    cin >> n;

    for (int i = 0, t, te = n; i < n; i++) {
        cin >> t;
        ok[t] = 1;
        while (te > 0 && ok[te]) {
            cout << te << " ";
            te--;
        }
        cout << endl;
    }
    return 0;
}
