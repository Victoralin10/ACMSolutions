#include <bits/stdc++.h>
#define MAXN 300005

using namespace std;

int n, N[MAXN];
long long A[MAXN];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }

  sort(N, N + n);

  A[n] = 0;
  for (int i = n-1; i >= 0; i--) {
    A[i] = A[i+1] + N[i];
  }

  long long ans = A[0];
  for (int i = 0; i + 1 < n; i++) {
    ans += N[i] + A[i+1];
  }

  cout << ans << endl;
}
