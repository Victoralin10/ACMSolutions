#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, a, b) for (int i = a; i < b; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v) v.begin(), v.end()
#define SZ(v) ((int)(v).size())
#define TEST(x) cerr << "test " << #x << " " << x << endl;

using namespace std;

clock_t _inicio = clock();

typedef long long Long;
typedef vector <int> vInt;
typedef pair <int, int> Pair;

set<char> ma, fe;
vector<char> pma[27];
vector<char> pfe[27];

int cmma[27]; // for each male
int cmfe[27];

char dummy[54];

int main(int nargs, char **args) {
    int tc;
    scanf("%d", &tc);
    REP (itc, tc) {
        int n;
        scanf("%d", &n);
        ma.clear();fe.clear();
        REP (i, n) {
            scanf("%s", dummy);
            ma.insert(dummy[0] - 'a');
        }
        REP (i, n) {
            scanf("%s", dummy);
            fe.insert(dummy[0] - 'A');
        }

        REP (i, n) {
            scanf("%s", dummy);
            int cma = dummy[0];
            pma[cma - 'a'].clear();
            REP (j, n) {
                pma[cma - 'a'].push_back(dummy[j + 2] - 'A');
            }
        }

        REP (i, n) {
            scanf("%s", dummy);
            int cfe = dummy[0];
            pma[cfe - 'A'].clear();
            REP (j, n) {
                pma[cfe - 'A'].push_back(dummy[j + 2] - 'a');
            }
        }

        clr(cmma, -1);

        while (1) {
            for (auto v : ma) {
                if (cmma[v] == -1) {
                    int pr = *pma[v].begin();
                    bool rep = 0;
                    REP (i, SZ(pfe[pr])) {
                        int mt = pfe[pr][i];
                        if (mt == cmfe[pr]) break;
                        if (mt == v) {
                            rep = 1;
                        }
                    }
                    if (rep) {
                        if (cmfe[pr] != -1) {
                            int cuernos = cmfe[pr];
                            cmma[cuernos] = -1;
                            REP (j, SZ(pma[cuernos])) {
                                if (pma[cuernos][j] == pr) {
                                    pma[cuernos].erase(pma[cuernos].begin() + j);
                                    break;
                                }
                            }
                        }
                        cmma[v] = pr;
                        cmfe[pr] = v;
                    }
                }
            }
        }
        

        
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
