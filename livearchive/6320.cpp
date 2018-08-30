#include<bits/stdc++.h>

using namespace std;

int cntA[35], cntB[50];

bool check() {
  for(int i=0; i<30; ++i)
    if (cntA[i] != cntB[i])
      return false;
  return true;
}

string a, b;

int main() {
  int T;
  cin>>T;
  while (T--) {
    cin>>a>>b;
    memset(cntB, 0, sizeof(cntB));
    memset(cntA, 0, sizeof(cntA));

    for(int i=0; i<b.size(); ++i)
      cntB[b[i]-'a']++;
    int lo = 0, hi = 0;
    while (hi - lo < b.size()) {
      cntA[a[hi]-'a']++;
      ++hi;
    }
    bool ok = 0;
    if (check()) ok = 1;
    while (hi < a.size()) {
      cntA[a[hi]-'a']++;
      hi++;
      cntA[a[lo]-'a']--;
      lo++;
      ok = ok || check();
    }
    if (ok) puts("YES");
    else puts("NO");
  }
}
