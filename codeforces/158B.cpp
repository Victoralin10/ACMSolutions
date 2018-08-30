#include <iostream>

using namespace std;

int main() {
    int n, A[] = {0,0,0,0,0};
    cin >> n;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        A[x]++;
    }

    int ans = 0, xd;

    ans += A[3] + A[4];
    A[1] -= min(A[3], A[1]);

    ans += A[2]/2;
    A[2] %= 2;

    if (A[2] > 0) {
        ans++;
        A[1] -= 2;
    }

    if (A[1] > 0) {
        ans += (A[1] - 1)/4 + 1;
    }

    cout << ans << endl;
}