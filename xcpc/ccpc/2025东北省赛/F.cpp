#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int x[3] {};
    int y[3] {};
    cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

    auto clok = [&](int x, int y) {
        return x * 60 + y;
    };

    int sh = x[0] * 60 + y[0];
    int sm = y[0] * 12;

    int time[4] {};
    time[1] = clok(x[1], y[1]);
    time[2] = clok(x[2], y[2]);

    auto dist = [&](int x, int y) {
        return min(abs(x - y), 720 - abs(x - y));
    };

    int mn = inf;
    int tx = 0, ty = 0;
    for(int i = 0; i <= 11; i ++) {
        for(int j = 0; j <= 59; j ++) {
            int ch = i * 60 + j;
            int cm = j * 12;
            int d = dist(sm, cm) + dist(sh, ch);

            int cur = clok(i, j);
            if(mn > d && (cur >= time[1] && cur <= time[2])) {
                mn = d;
                tx = i, ty = j;
            }
        }
    }

    cout << tx << ' ' << ty << '\n';
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
