#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int N = 1e6 + 10;
int p[N];

int find(int x) {
    if(x != p[x]) {
        p[x] = find(p[x]);
    }
    return p[x];
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        p[i] = i;
    }
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        x = find(x), y = find(y);
        p[x] = y;
    }

    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        if(i == find(i)) {
            cnt ++;
        }
    }

    cout << m - n + cnt * 2 - 1 << '\n';
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
