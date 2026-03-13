#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;
const int mod = 998244353;

i64 f(i64 x) {
    string s = to_string(x);
    i64 res = 1;
    for(auto c : s) {
        res *= c - '0';
    }
    return res;
}

int g(i64 x) {
    int cnt = 0;
    while(x != f(x)) {
        cnt ++;
        x = f(x);
    }
    return cnt;
}

void solve() {
    i64 mx[2] {};
    i64 v[2] {};
    i64 w[2] {};
    auto dfs = [&](auto &&self, i64 x, int d, i64 y, i64 z) {
        if(x == 10) {
            if(y == v[0] || y == v[1]) {
                return;
            }
            int c = g(y);
            if(c > mx[0]) {
                mx[1] = mx[0];
                v[1] = v[0];
                w[1] = w[0];
                mx[0] = c;
                v[0] = y;
                w[0] = z;
            } else if(c > mx[1]) {
                mx[1] = c;
                v[1] = y;
                w[1] = z;
            }
            return;
        }

        for(int i = 0; i + d <= 18; i ++) {
            if(i) {
                y *= x;
                z = z * 10 + x;
            }
            self(self, x + 1, d + i, y, z);
        }
    };

    dfs(dfs, 2, 0, 1, 0);
    cout << w[0] << ' ' << w[1] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
