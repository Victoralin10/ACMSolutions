
struct Point {
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}

    Point ort() { return Point(-y, x); }
    double mod2() { return x*x + y*y; }
    double mod() { return sqrt(mod2()); }

    Point unit() {
        double md = mod();
        return Point(x/md, y/md);
    }
};

Point operator+ (const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator- (const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
}

double operator* (const Point &a, const Point &b) {
    return a.x*b.x + a.y*b.y;
}

Point operator* (const Point &a, double k) {
    return Point(a.x*k, a.y*k);
}

Point operator* (double k, const Point &a) {
    return Point(a.x*k, a.y*k);
}

bool inInterval(const Point &a, const Point &b, const Point &c) {
    return ((a - b)*(c - a).ort() == 0) && ((c - a)*(c - b) <= 0);
}

Point proyeccion(const Point &a, const Point &b, const Point &c) {
    Point u = b - a;
    return a + (((c - a)*u)/(u*u))*u;
}

double distance(const Point &a, const Point &b, const Point &c) {
    Point p = proyeccion(a, b, c);
    if (inInterval(a, b, p)) {
        return (c - p).mod();
    }

    return min((c - a).mod(), (c - b).mod());
}

Point interseccion(const Point &a, const Point &b, const Point &c,
    const Point &d) {

    Point u1 = (b - a), u2 = (d - c);
    return a + (((c - a)*u2.ort())/(u1*u2.ort()))*u1;
}
