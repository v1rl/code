#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
参数 x 与 y 的通解为x + b / gcd(a, b) * n，y - a / gcd(a, b) * n  (n 为任意整数)
*/

int exgcd(int a, int b, int &x, int &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }
    int t = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return t;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int a, m;
    cin >> a >> m;
    int x, y;
    int t = exgcd(a, m, x, y);

    int mx = m / t;
    int my = -a / t;

    int ansx = (x % mx + mx) % mx;
    int ansy = y + (ansx - x) / mx * my;
    cout << ansx << ' ' << ansy << '\n';
}