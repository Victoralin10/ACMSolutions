#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int main() {
  long long a, b;
  cin >> a >> b;

  long long x = ((b*(b-1))/2) % MOD;
  long long y = (a + b*((a*(a+1))/2 % MOD)) % MOD;
  cout << x*y % MOD << endl;
}
