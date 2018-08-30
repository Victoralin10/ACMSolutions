#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()
#define fi first
#define se second
#define ll long long
#define ull long long
#define ld long double


using namespace std;


int main(int nargs, char **args) {
    int N[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int m, d;
    cin >> m >> d;

    cout << (N[m - 1] + d - 2)/7 + 1 << endl;

    return 0;
}
