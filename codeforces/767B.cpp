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

ll ts, tf, t, A[MAXN];
int n;

int main(int nargs, char **args) {
    cin >> ts >> tf >> t >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll ta = -1, tespera = (1LL<<50);

    if (A[0] > ts) {
        tespera = 0;
        ta = ts;
    }
    for (int i = 0, j = 0; i < n; i++) {
        if (max(ts - A[i] + 1, 0LL) < tespera) {
            tespera = max(ts - A[i] + 1, 0LL);
            ta = A[i] - 1;
        }
        // cout << ta << " " << tespera << endl;
        j = i;
        while (j < n && A[i] == A[j]) {
            ts = max(ts + t, A[i] + t);
            j++;
        }
        i = j-1;
        if (ts + t > tf) break;
    }
    
    if (ts + t <= tf) {
        ta = ts;
    }
    cout << ta << endl;

    return 0;
}
