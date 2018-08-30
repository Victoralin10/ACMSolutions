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

int n, A[MAXN];
int dp[MAXN];

int main(int nargs, char **args) {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    dp[0] = 0;
    for (int i = 0, j = 0, k = 0; i < n; i++) {
        int &cdp = dp[i+1];
        cdp = 20 + dp[i];
        while (A[i] - A[j] >= 90) j++;
        while (A[i] - A[k] >= 1440) k++;
        cdp = min(cdp, 50 + dp[j]);
        cdp = min(cdp, 120 + dp[k]);

        //cout << A[i] << " " << cdp << endl;
    }

    int cb = 0, p;
    for (int i = 1; i <= n; i++) {
        p = max(0, dp[i] - cb);
        cout << p << endl;

        cb += p;
    }

    return 0;
}
