#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);

    function<int(int)> find = [&](int x) {
        if(x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    };

    while(m --) {
        char op;
        cin >> op;
        int x, y;
        cin >> x >> y;
        x = find(x), y = find(y);
        if(op == 'M') {
            p[y] = x;
        } else {
            cout << (x == y ? "Yes" : "No") << '\n';
        }
    }
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
