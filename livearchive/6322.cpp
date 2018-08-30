/**
* Title:            (program's title)
* Author:           Victor Cueva Llanos
* Email:            Ingvcueva@gmail.com
**/

#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 1001

using namespace std;

set <char> st[MAXN];
int n;
map <char, int> mp;

bool isPosible(int px, char c) {
  mp[c]--;
  bool ans = true;
  for (int i = px+1;i < n && ans;i++) {
    bool xd = false;
    for (set <char>::iterator it = st[i].begin();it != st[i].end();it++) {
      if (mp[*it] > 0){
        xd = true;
        break;
      }
    }
    ans = ans && xd;
  }
  mp[c++];
  return ans;
}

/*void eliminar(int px, char c) {
  for (int i = px+1;i < n;i++) {
    st[i].erase(c);
  }
}*/

int main(int nargs, char **args) {
    // clock_t _inicio = clock();
    int t;
    cin >> t;
    while (t--) {
      string line, xd, ans;
      cin >> line;

      n = line.size();
      mp.clear();
      for (int i = 0;i < n;i++) {
        st[i].clear();
        mp[line[i]]++;

        cin >> xd;
        for (int j = 0;j < xd.size();j++) {
          st[i].insert(xd[j]);
        }
      }

      ans = line;
      sort(ans.begin(), ans.end());

      for (int i = 0;i < n;i++) {
        int ind = -1;
        for (int j = i;j < n;j++) {
          if (st[i].find(ans[j]) == st[i].end()) continue;
          if (isPosible(i, ans[j])) {
            ind = j;
            break;
          }
        }
        if (ind < 0) {
          ans == line;
          break;
        }
        for (int j = ind-1;j >= i;j--) {
          swap(ans[j], ans[j+1]);
        }
        //eliminar(i, ans[i]);
        mp[ans[i]]--;
      }

      if (ans == line) {
        cout << "NO SOLUTION" << endl;
      } else {
        cout << ans << endl;
      }
    }

    // printf("Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
