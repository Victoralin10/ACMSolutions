#include <bits/stdc++.h>

using namespace std;

map<pair <int, int>, int> st;
vector <int> fb;

int main() {
    int a = 0, b = 1, ind = 1;
    fb.push_back(0);
    fb.push_back(1);
    
    st[make_pair(a, b)] = ind++;
    pair <int, int> key;
    do {
        a = a+b;
        a %= 10;
        b %= 10;
        swap(a, b);
        key = make_pair(a, b);
        if (st.find(key) != st.end()) {
            break;
        }
        fb.push_back(b);
        st[key] = ind++;
    } while (true);

    // cout << ind << endl;

    int t, m;
    cin >> t;
    while (t--) {
        cin >> m;
        m++;
        if (m <= ind) cout << fb[m] << endl;
        else {
            int period = ind - st[key];
            cout << fb[(m - st[key])%period] << endl;
        }
    }
}