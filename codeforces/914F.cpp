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

bitset<MAXN> B[27], ans, ones;
char s[MAXN], s2[MAXN];

int main(int nargs, char **args) {
    scanf("%s", s + 1);
    int len, q, t, l, r, len2;
    len = strlen(s + 1);
    for (int i = 1; i <= len; i++) {
        B[s[i] - 'a'][i] = 1;
    }
    ones = ~ones;

    scanf("%d", &q);
    while (q--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%s", &l, s2);
            B[s[l] - 'a'][l] = 0;
            s[l] = s2[0];
            B[s2[0] - 'a'][l] = 1;
        } else {
            scanf("%d%d%s", &l, &r, s2);
            len2 = strlen(s2);
            if (r - l + 1 < len2) {
                puts("0");
                continue;
            }
            ans = ones;
            for (int i = 0; i < len2; i++) {
                ans &= (B[s2[i] - 'a']>>i);
            }

            ans >>= l;
            cout << ans.count() - (ans>>(r - l - len2 + 2)).count() << endl;
        }
    }

    return 0;
}
