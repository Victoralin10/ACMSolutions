#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 10

#define pb push_back
#define mp make_pair
#define pii pair <int, int>
#define all(v) (v).begin() (v).end()


using namespace std;

int A[4];

int main(int nargs, char **args) {
    string colors = "RBYG", line;
    cin >> line;

    string x = "!!!!";

    for (int i = 0; i < line.size(); i++) {
        A[i%4] += line[i] == '!';
        if (line[i] != '!') {
            x[i%4] = line[i];
        }
    }

    for (int i = 0; i < 4; i++) {
        printf("%d%c", A[x.find(colors[i])], i==3?'\n':' ');
    }
}
