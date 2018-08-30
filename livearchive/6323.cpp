#include<bits/stdc++.h>
#define sc(x) scanf("%d", &(x))
#define endl "\n"
#define me(a,v) memset(a, v, sizeof(a))
#define FN(i, n) for(int (i) = 0; (i) < (n) ; (i)++)
#define FOR(i, st, n) for(int (i) = (st); (i) < (n) ; (i)++)
using namespace std;

int n;
int l;

int code(int x, int y) {
  return 4*x + y;
}

void decode(int val, int &x, int &y) {
  x = val/4;
  y = val%4;
}

int memo[1<<12][12][1000];

int dx1[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy1[] = {-1, 1, 1, -1, 0, 0, 1, -1};

int dp(int mask, int last, int le) {
  if (le == 0) return 1;

  int &res = memo[mask][last][le];
  if (res != -1) return res;
  res = 0;
  int x, y;
  decode(last, x, y);
  FN (i, 8) {
    int sx = x + dx1[i];
    int sy = y + dy1[i];
    if (sx >= 0 && sx < 3 && sy < 4 && sy >= 0) {
      int son = code(sx, sy);
      int al = abs(sx - x) + abs(sy - y);// added length
      if (!(mask&(1<<son)) && al <= le) {
        // first level
        res += dp(mask|(1<<son), son, le - al);
      } else {
        // second level
        int sx2 = sx + dx1[i];
        int sy2 = sy + dy1[i];
        if (sx2 >= 0 && sx2 < 3 && sy2 < 4 && sy2 >= 0) {
          int son2 = code(sx2, sy2);
          int al2 = abs(sx2 - x) + abs(sy2 - y);// added length
          if (!(mask&(1<<son2)) && al2 <= le) {
            res += dp(mask|(1<<son2), son2, le - al2);
          }
        }
      }
    }
  }

  FOR (i, -3, 4) {
    FOR (j, -3, 4) {
      if (i != j && i != 0 && j != 0 && i != -j) {
          int sx = x + i;
          int sy = y + j;
          if (sx >= 0 && sx < 3 && sy < 4 && sy >= 0) {
            int son = code(sx, sy);
            int al = abs(sx - x) + abs(sy - y);// added length
            if (!(mask&(1<<son)) && al <= le) {
              res += dp(mask|(1<<son), son, le - al);
            }
          }
      }
    }
  }
  //cout << x << " " << y << " " << mask << " "<< le << " " << res << endl;
  return res;
}


int main() {
  int tc;
  me(memo, -1);
  sc(tc);
  FN (itc, tc) {
    sc(l);
    sc(n);
    int mask = 0;
    FN (i, n) {
      int x, y;
      sc(x);sc(y);
      x--; y--;
      int e = code(x, y);
      mask |= (1<<e);
    }
    int ans = 0;
    FN (i, 3) {
      FN (j, 4) {
        int la = code(i, j);
        if ( !(mask&(1<<la)) ) {
          ans += dp(mask|(1<<la), la, l);
        }
      }
    }
    if (ans == 0) {
      puts("BAD MEMORY");
    } else {
      cout << ans << endl;
    }


  }
}
