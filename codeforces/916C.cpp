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

bool isPrime(int n) {
    if (n == 2) return 1;
    if ((n&1) == 0) return 0;
    for (int i = 3; i*i <= n; i += 2) {
        if (n%i == 0) return false;
    }

    return true;
}

int main(int nargs, char **args) {
    int n, m, np;
    cin >> n >> m;

    np = n;
    while (!isPrime(np)) np++;

    cout << "2 " << np << endl;
    cout << "1 " << n << " 2" << endl;
    if (n > 2) {
        cout << "1 2 " << 1 + np - n << endl; 
    }
    for (int i = 3; i < n; i++) {
        cout << i-1 << " " << i << " 1" << endl;
    }
    m -= n - 1;
    for (int i = 1; i < n && m; i++) {
        for (int j = n - (i==1); j > i+1 && m; j--) {
            cout << i << " " << j << " 100" << endl;
            m--;
        }
    }
    if (m) {
        cout << n-1 << " " << n << " 100" << endl;
    }

    return 0;
}
