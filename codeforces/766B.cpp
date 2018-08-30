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

int A[MAXN];

int main(int nargs, char **args) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A, A + n);

    bool ok = 0;
    for (int i = 2; i < n && !ok; i++) {
        ok = (A[i] < A[i-2] + A[i-1] && A[i] > A[i-1] - A[i-2]
            && A[i-1] > A[i] - A[i-2] && A[i-1] < A[i-2] + A[i-1]
            && A[i-2] > A[i] - A[i-1] && A[i-1] < A[i] + A[i-1]);
    }

    puts(ok?"YES":"NO");

    return 0;
}
