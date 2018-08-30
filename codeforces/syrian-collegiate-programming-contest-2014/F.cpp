#include <bits/stdc++.h>

using namespace std;


int main(int nargs, char **args) {
    int t;
    long long n, m;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; caso++) {
        cin >> n >> m;
        long long lo = 0, hi = (1LL<<31), mid;
        while (hi - lo > 1) {
            mid = (lo + hi)/2;
            if ((mid*(mid+1))/2 >= m) hi = mid;
            else lo = mid;
        }
        cout << "Case " << caso << ": " << lo << " " << m - (lo*(lo+1))/2  - 1 << endl;
    }

    return 0;
}
