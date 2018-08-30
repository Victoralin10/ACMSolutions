#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define ll long long

using namespace std;


int main(int nargs, char **args) {
    clock_t _inicio = clock();

    int n, a, mx = -(1<<30);
    cin >> n;

    ll s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        s += a;
        mx = max(mx, a);
    }

    cout << mx*n - s << endl;

    fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
