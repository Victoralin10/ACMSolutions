#include<bits/stdc++.h>
#define sc(x) scanf("%d", &(x))
using namespace std;

int main() {
  int tc;
  sc(tc);
  for (int itc = 0; itc < tc; itc ++) {
    int n, k;
    sc(n);
    sc(k);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int aux;
      sc(aux);
      cnt += aux/k;
    }
    printf("%d\n", cnt);
  }
}
