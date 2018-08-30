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
#define MAXN 200005

using namespace std;


int A[MAXN];

int main(int nargs, char **args) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    for (int i = 0, j = n-1; i < j; i += 2, j -= 2) {
        swap(A[i], A[j]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%c", A[i], i+1==n?'\n':' ');
    }
    return 0;
}
