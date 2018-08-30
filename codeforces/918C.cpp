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
#define MAXN 5003

using namespace std;

char s[MAXN];

int main(int nargs, char **args) {
    scanf("%s", s);
    int l = strlen(s), ans = 0;
    for (int i = 0; i < l; i++) {
        for (int j = i, pre = 0, cnt = 0; j < l; j++) {
            if (s[j] == '(') pre++;
            else if (s[j] == ')') pre--;
            else cnt++;
            if (pre + cnt < 0) break;
            if ((pre + cnt)&1) continue;
            if (pre <= cnt) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
