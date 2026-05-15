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
    i64 c, a, b;
    cin >> c >> a >> b;

    i64 x, y;
    i64 g = exgcd(a, b, x, y);
    if(c % g != 0) {
        cout << "No" << '\n';
        return;
    }

    i64 times = c / g;
    i64 modx = b / g, mody = a / g;

    x = ((i128)x * times % modx + modx) % modx;
    y = (c - (i128)a * x) / b;

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

    i64 cnt = (y - x) / (modx + mody);
    x += cnt * modx;
    y -= cnt * mody;

    if(y >= mody && max(x, y) > max(x + modx, y - mody)) {
        x += modx;
        y -= mody;
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
