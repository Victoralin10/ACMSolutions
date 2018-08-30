#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 100

#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define ll long long
#define ull unsigned long long

using namespace std;

char s[100];
int D[100];
int n, l;

ll Pot10[MAXN];

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    cin >> n >> s;

    l = strlen(s);
    for (int i = 0; i < l; i++) {
        D[i] = s[i] - '0';
    }

    if (n <= 10) {
        ll ans = 0;
        for (int i = 0; i < l; i++) {
            ans = ans*n + D[i];
        }
        cout << ans << endl;

        return 0;
    }

    Pot10[0] = 1;
    for (int i = 1; i <= 10; i++) {
        Pot10[i] = Pot10[i - 1]*10;
    }

    ll A[MAXN];
    int pa = 0;
    
    for (int i = l - 1, j; i >= 0; ) {
        ll d = 0;
        j = i;

        while (j >= 0 && d + D[j]*Pot10[i - j] < n) {
            d += D[j]*Pot10[i - j];
            j--;
        }

        while (j < i - 1 && D[j + 1] == 0) {
            j++;
        }

        A[pa++] = d;
        i = j;
    }

    ull ans = 0;
    for (int i = pa - 1; i >= 0; i--) {
        ans = ans*n + A[i];
    }
    
    cout << ans << endl;

    return 0;
}
