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


vector <vector <string> > getCases() {
    vector <vector <string> > ans;
    string line;
    vector <string> currentCase;
    while (getline(cin, line)) {
        int i = 0;
        REP(j, SZ(line)) 
            if (line[j] != ' ') line[i++] = line[j];
        while (SZ(line) > i) line.pop_back();

        if (line == "") {
            if (SZ(currentCase)) ans.push_back(currentCase);
            currentCase.clear();
        } else {
            currentCase.push_back(line);
        }
    }

    if (SZ(currentCase)) ans.push_back(currentCase);
    return ans;
}

vector <Long> solveCase(vector<string> &caso) {
    map <char, int> mp;
    REP(i, SZ(caso[0])) {
        mp[caso[0][i]] = i;
    }
    vector <Long> ans;

    REPR(i, 1, SZ(caso)) {
        string num = caso[i];
        int a = 0, b = SZ(caso[0]);
        REP(j, SZ(num)) {
            a = max(a, mp[num[j]]);
        }
        a++;

        reverse(all(num));
        vector <Long> pot(b - a + 1, 1);
        Long sum = 0;
        REP(j, SZ(num)) {
            Long lsum = 0;
            REP(k, SZ(pot)) lsum += pot[k];
            sum += mp[num[j]]*lsum;
            REPR(k, a, b + 1) {
                pot[k-a] *= k;
            }
        }
        ans.push_back(sum);
    }

    return ans;
}

int main(int nargs, char **args) {
    vector <vector <string> > casos = getCases();

    bool pri = true;
    for (vector <string> &caso: casos) {
        vector <Long> sol = solveCase(caso);
        if (!pri) {
            cout << endl;
        } else {
            pri = false;
        }

        for (Long x: sol) {
            cout << x << endl;
        }
    }
    // cerr << "Time elapsed: " << (clock() - _inicio)/1000 << " ms" << endl;
    return 0;
}
