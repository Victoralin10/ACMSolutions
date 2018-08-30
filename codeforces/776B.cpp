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

int C[MAXN];
set <int> st[MAXN], st1;

int main(int nargs, char **args) {
    int n;
    cin >> n;

    for (int i = 2; i <= n + 1; i++) {
        int c = 1;
        while (st[i].find(c) != st[i].end()) c++;

        if (st[i].size() == 0) {
            for (int j = 2*i; j <= n+1; j += i) {
                st[j].insert(c);
            }
        }

        st1.insert(c);
        C[i] = c;
    }

    printf("%d\n", st1.size());
    for (int i = 2; i <= n+1; i++) {
        printf("%d%c", C[i], i==n+1?'\n': ' ');
    }

    return 0;
}
