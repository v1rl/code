#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
双自由度的情况下想找最小值并不容易
注意到：两个点的运动都是匀速，它们的移动和时间是线性关系，它们的距离（线性关系相减）也是线性关系
于是，距离与时间的函数关系是线性关系，我们只需要知道初始点和结束点，原点到这两个点构成的线段的最短距离即为答案
但二者并不是任意时刻都在匀速移动的，路程更短的那一方会更先停止
停止后，两点的距离与时间仍是线性关系，但线性函数会相应发生变化，也就是与原来的线段不在同一条直线上
所以我们需要以停止为分界点，讨论两条线段
*/

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

// 点 P 到线段 AB 的距离 (本题核心)
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

double check(double x, const Point &a, const Point &b) {
    Point mid = a + (b - a) * x;
    return mid.len();
}

double xts(const Point &a, const Point &b) {
    double l = 0.0, r = 1.0;
    for(int i = 0; i < 100; i ++) {
        double mid1 = l + (r - l) / 3.0;
        double mid2 = r - (r - l) / 3.0;

        if(check(mid1, a, b) > check(mid2, a, b)) {
            l = mid1;
        } else {
            r = mid2;
        }
    }
    return l;
}

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

    // 需要注意，计算几何在任意用到除法的地方都要考虑是否会发生除0错误
    Point mid2 = (sgn(q) ? s2 + (t2 - s2) * (p / q) : s2);

    Point A = s1 - s2;
    Point B = t1 - mid2;
    Point C = t1 - t2;

    Point O = {0, 0};

    // cout << min(distToSegment(O, A, B), distToSegment(O, B, C)) << '\n';
    cout << min(check(xts(A, B), A, B), check(xts(B, C), B, C)) << '\n';

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