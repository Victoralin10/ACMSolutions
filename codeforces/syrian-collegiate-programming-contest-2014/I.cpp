#include <bits/stdc++.h>

using namespace std;

int main(int nargs, char **args) {
    int t;
    cin >> t;
    for (int caso = 1; caso <= t; caso++) {
        string line;
        pair <int, int> F[30];
        for (int i = 0; i < 26; i++) {
            F[i] = make_pair(0, i);
        }

        while (getline(cin, line)) {
            if (line == "*") break;
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == ' ') continue;
                F[tolower(line[i]) - 'a'].first++;
            }
        }

        sort(F, F + 26);
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            if (F[25 - i].first > 0) {
                sum += F[25 - i].second;
            }
        }

        printf("Case %d: %s\n", caso, (sum>62?"Effective":"Ineffective"));
    }
    return 0;
}
