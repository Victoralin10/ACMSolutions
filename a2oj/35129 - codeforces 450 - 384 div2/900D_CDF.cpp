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
#define MAXN 50004

using namespace std;

int fast_pow(int b, int e) {
    int ans = 1;
    while (e) {
        if ((e&1)) ans = ((ll)ans*b) % MOD;
        b = ((ll)b*b) % MOD;
        e >>= 1;
    }
    return ans;
}

int V[MAXN], cnt = 0, A[MAXN];

int main(int nargs, char **args) {
    int x, y;
    cin >> x >> y;
    if (y%x != 0) {
        puts("0");
    } else {
        y /= x;
        for (int i = 1; i*i <= y; i++) {
            if (y%i == 0) {
                V[cnt++] = i;
                if (i != y/i) {
                    V[cnt++] = y/i;
                }
            }
        }
        sort(V, V + cnt);
        for (int i = 0; i < cnt; i++) {
            A[i] = fast_pow(2, V[i] - 1);
        }
        for (int i = 0; i < cnt; i++) {
            for (int j = i+1; j < cnt; j++){
                if (V[j]%V[i] == 0) {
                    A[j] = (A[j] + MOD - A[i])%MOD;
                }
            }
        }
        cout << A[cnt - 1] << endl;
    }

    return 0;
}
