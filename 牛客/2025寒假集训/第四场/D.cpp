#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;
const int mod = 998244353;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if(!b) {
        x = 1, y = 0;
        return a;
    }

    i64 g = exgcd(b, a % b, y, x);
    y -= a / b * x;

    return g;
}

void solve() {
    i64 d, a, b;
    cin >> d >> a >> b;

    i64 x, y;
    if(d % gcd(a, b) != 0) {
        cout << "No" << '\n';
        return;
    }
    i64 g = exgcd(a, b, x, y);

    i64 p = d / g;
    i64 mx = b / g, my = a / g;

    x = ((i128)x * p % mx + mx) % mx;
    y = (d - (i128)a * x) / b;

    if(y < 0) {
        cout << "No" << '\n';
        return;
    }

    if(x >= y) {
        cout << "Yes" << '\n';
        cout << x << ' ' << y << '\n';
        return;
    }

    cout << "Yes" << '\n';

    i64 t = (y - x) / (mx + my);
    x += t * mx;
    y -= t * my;

    if(y >= my && max(x, y) > max(x + mx, y - my)) {
        x += mx;
        y -= my;
    }

    cout << x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
