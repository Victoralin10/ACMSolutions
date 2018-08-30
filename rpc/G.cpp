#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define clr(t, val) memset(t, val, sizeof(t))
#define all(v)  v.begin(), v.end()
#define SZ(v) ((int)(v).size())

using namespace std;

typedef long long Long;
typedef vector <int> vInt;
typedef vector <vInt> vvInt;
typedef vector <string> vStr;
typedef pair <int, int> Pair;
typedef vector <pair <int, int> > vPair;

struct Point {
    int x, y, z;
    Point(){}
    Point(int x, int y, int z):x(x), y(y), z(z){}
    void read() {
        cin >> x >> y >> z;
    }
    bool isO() {
        return abs(x) + abs(y) + abs(z) == 0;
    }
    void print() {
        printf("(%d %d %d)", x, y, z);
    }
};

bool operator==(const Point &a, const Point &b) {
    return a.x==b.x && a.y==b.y && a.z==b.z;
}

Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}

Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}

void f(int &x, int &y) {
    if (y > 0) {
        y--;
        x++;
    } else {
        y++;
        x--;
    }
}

void next(Point &p, Point &d) {
    if (d.x) {
        f(p.x, d.x);
    } else if (d.y) {
        f(p.y, d.y);
    } else if(d.z) {
        f(p.z, d.z);
    }
}

int main(int nargs, char **args) {
    clock_t _inicio = clock();

    Point p1, v1, p2, v2;
    p1.read();
    v1.read();
    p2.read();
    v2.read();
    v1 = v1 - p1;
    v2 = v2 - p2;

    p1.print();
    cout << " ";
    p2.print();
    cout << endl;
    while (!v1.isO() || !v2.isO()) {
        Point p1a = p1;
        next(p1, v1);

        Point p2a = p2, v2a = v2;
        next(p2, v2);
        if (p1 == p2) {
            p2 = p2a;
            v2 = v2a;
        } else if (p1 == p2a && p2 == p1a) {
            int i = rand()%2;
            if (!i) i--;    
            if (v2a.x == v2.x) {
                p2 = p2a;
                v2 = v2a;
                p2.x += i;
                v2.x -= i;
            } else {
                p2 = p2a;
                v2 = v2a;
                p2.y += i;
                v2.y -= i;
            }
        }

        p1.print();
        cout << " ";
        p2.print();
        cout << endl;
    }

    // fprintf(stderr, "Time elapsed: %ld ms\n", (clock() - _inicio)/1000);
    return 0;
}
