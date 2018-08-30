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
    int n, m;
    cin >> n >> m;
    double a, b, ans = (1<<30);
    while (n--) {
        cin >> a >> b;
        ans = min(ans, m*a/b);
    }
    printf("%.8f\n", ans);
    
    return 0;
}
