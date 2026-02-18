#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
参数 x 与 y 的通解为x + b / gcd(a, b) * n，y - a / gcd(a, b) * n  (n 为任意整数)
*/

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    // int g = exgcd(b, a % b, x, y);
    // int z = x;               // 暂存 x'
    // x = y;                   // x_new = y_old
    // y = z - (a / b) * y;     // y_new = x_old - (a/b) * y_old

    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return g;
}

// linear congruence equation
// 返回最小非负解 x0（模 m/g），无解返回 -1
// 模m意义下所有解为 x = x0 + k*(m/g) (k=0..g-1)
i64 lce(i64 a, i64 b, i64 m) {
    i64 x, y;
    i64 g = exgcd(a, m, x, y);

    if (b % g != 0) {
        return -1;
    }

    i64 m0 = m / g;
    return (b / g * x % m0 + m0) % m0;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    i64 a, m;
    cin >> a >> m;
    i64 x, y;
    i64 t = exgcd(a, m, x, y);

    i64 modx = m / t;
    i64 mody = -a / t;

    x = (x % modx + modx) % modx;
    y = (t - x * a) / m;
    cout << x << ' ' << y << '\n';
    cout << lce(-3, 2, 7) << '\n';
}