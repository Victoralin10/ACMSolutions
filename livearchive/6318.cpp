#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 128;

int A[kMaxN][kMaxN];
int cnt[kMaxN];

int main() {
  int T, C, V;
  cin>>T;
  while (T--) {
    cin>>C>>V;
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<V; ++i)
      for(int j=0; j<C; ++j) {
        cin>>A[i][j];
      }

    for(int i=0; i<V; ++i)
      cnt[A[i][0]]++;

    int maxi = 0, win1=0, win2=0;

    for(int i=1; i<=C; ++i) {
      if (maxi < cnt[i]) {
        maxi = cnt[i];
        win1 = i;
      }
    }

    if (maxi*2 > V) {
      cout<<win1<<" "<<1<<endl;
    } else {
      maxi = 0;
      for(int i=1; i<=C; ++i)
        if (i != win1 && cnt[i]>=maxi) {
          maxi = cnt[i];
          win2 = i;
        }
      int vote1 = 0, vote2 = 0;
      for(int i=0; i<V; ++i) {
        for(int j=0; j<C; ++j) {
          if (A[i][j] == win1) {
            vote1++;
            break;
          }
          if (A[i][j] == win2) {
            vote2++;
            break;
          }
        }
      }
      if (vote1 >= vote2) cout<<win1<<" "<<2<<endl;
      else cout<<win2<<" "<<2<<endl;
    }

  }
}
