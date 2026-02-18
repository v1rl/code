#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const double EPS = 1e-9;
const double PI = acos(-1.0);

int sgn(double x) {
    if (fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
}

struct Point {
    double x, y;

    Point(double _x = 0, double _y = 0) : x(_x), y(_y) {}

    Point operator + (const Point &b) const { return Point(x + b.x, y + b.y); }
    Point operator - (const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator * (double k) const { return Point(x * k, y * k); }
    Point operator / (double k) const { return Point(x / k, y / k); }

    bool operator < (const Point &b) const {
        return sgn(x - b.x) == 0 ? sgn(y - b.y) < 0 : x < b.x;
    }
    bool operator == (const Point &b) const {
        return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
    }

    double sqrLen() const { return x * x + y * y; }
    double len() const { return sqrt(sqrLen()); }
    
    // 向量旋转 (逆时针旋转 angle 弧度)
    // 公式: x' = x cos - y sin, y' = x sin + y cos
    Point rotate(double ag) const {
        return Point(x * cos(ag) - y * sin(ag), x * sin(ag) + y * cos(ag));
    }
    
    // 向量标准化 (变为单位向量)
    Point unit() const {
        double l = len();
        return l > EPS ? *this / l : Point(0, 0); // 防止除0
    }
    
    friend ostream& operator << (ostream &os, const Point &p) {
        return os << p.x << " " << p.y;
    }
    friend istream& operator >> (istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
};

struct Line {
    // 一般式：a x + b y + c = 0
    ld a, b, c;

    // 由两点构造直线
    static Line from_points(Point p, Point q) {
        // (y - yp)(xq - xp) = (x - xp)(yq - yp)
        // => (yq-yp)x - (xq-xp)y + (xq-xp)yp - (yq-yp)xp = 0
        ld a = (q.y - p.y);
        ld b = -(q.x - p.x);
        ld c = (q.x - p.x) * p.y - (q.y - p.y) * p.x;
        return {a, b, c};
    }
};

// 点积
// 代数公式: A·B = x1x2 + y1y2
// 几何公式: A·B = |A||B|cosθ
// 几何意义: 一个向量在另一个方向上的投影长度 × 另一个向量的长度
// 应用: 投影长度，夹角，方向一致性（>0方向相近，<0方向相反，=0正交）
double dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

// 叉积
// 几何公式: A×B = |A||B|sinθ
// 几何意义: 叉积的模 = 两向量张成的平行四边形面积 方向 = 同时垂直于a和b，由右手定则决定
// 应用：平行四边形面积，三角形面积，判断左右关系（>0 B在A左侧/逆时针，<0 B在A右侧/顺时针，=0共线）
double cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

// 两点间距离
double dist(const Point &a, const Point &b) {
    return (a - b).len();
}

// 点 P 到直线 AB 的距离 (A != B)
// 原理: 叉积算面积，除以底边长 = 高
double distToLine(const Point &p, const Point &a, const Point &b) {
    return fabs(cross(p - a, b - a)) / (b - a).len();
}

// 点 P 到线段 AB 的距离
// 分类讨论垂足位置，利用点积判断
double distToSegment(const Point &p, const Point &a, const Point &b) {
    if (a == b) return dist(p, a); // 线段退化为点
    
    // 情况1: 垂足在 A 的外侧 (点积 < 0 说明夹角钝角)
    if (sgn(dot(b - a, p - a)) < 0) return dist(p, a);
    
    // 情况2: 垂足在 B 的外侧 (点积 < 0 说明夹角钝角)
    if (sgn(dot(a - b, p - b)) < 0) return dist(p, b);
    
    // 情况3: 垂足在线段内部 -> 等同于到直线距离
    return distToLine(p, a, b);
}

// 点 P 在直线 AB 上的投影点
Point project(const Point &p, const Point &a, const Point &b) {
    Point v = b - a;
    // 这里没有用unit，而是直接AB * (在 AB 方向上，AP 占了 AB 的多少比例)
    return a + v * (dot(p - a, v) / v.sqrLen());
}

/*
*/

const int inf = 1e9;

void solve() {
    Point s1, t1, s2, t2;
    cin >> s1 >> t1 >> s2 >> t2;
    double p = dist(s1, t1);
    double q = dist(s2, t2);
    if(p > q) {
        swap(s1, s2);
        swap(t1, t2);
        swap(p, q);
    }

    Point mid2 = (sgn(q) ? s2 + (t2 - s2) * (p / q) : s2);

    Point A = s1 - s2;
    Point B = t1 - mid2;
    Point C = t1 - t2;

    Point O = {0, 0};
    cout << min(distToSegment(O, A, B), distToSegment(O, B, C)) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}