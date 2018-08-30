#include<bits/stdc++.h>

using namespace std;

string s, line, r;
char c;

int main() {
  int T, X, Y;
  ios_base::sync_with_stdio(false);
  cin>>T;
  while (T--) {
    cin>>s;
    getline(cin,line);
    while(getline(cin,line) ) {
      if (line == "END") break;
      istringstream in(line);
      in>>c;
      if (c == 'I') {
        in>>r>>X;
        s = s.substr(0, X) + r + s.substr(X);
      } else {
        in>>X>>Y;
        cout<<s.substr(X, Y-X+1)<<"\n";
      }
    }
  }
}
