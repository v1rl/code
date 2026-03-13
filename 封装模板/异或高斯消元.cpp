#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://www.luogu.com.cn/problem/P2962

const int N = 1000;
pair<int, bitset<N>> guass(int n, int m, auto g) {
    for(int x = 1; x <= m; x ++) {
        for(int i = 1; i <= n; i ++) {
            if(i < x && g[i][i] == 1) {
                continue;
            }
            if(g[i][x] == 1) {
                swap(g[i], g[x]);
                break;
            }
        }

        if(g[x][x] == 0) {
            continue;
        }

        for(int i = 1; i <= n; i ++) {
            if(i != x && g[i][x] == 1) {    
                g[i] ^= g[x];
            }
        }
    }

    int f = 1;
    bitset<N> ans;
    for(int x = 1; x <= m; x ++) {
        if(g[x][x] == 0) {
            f = 0;
            break;
        } else {
            ans[x] = g[x][m + 1];
        }
    }

    return {f, ans};
}


void solve() {
    int n, m;
    cin >> n >> m;

    vector g(m + 1, bitset<N + 2>());
    for(int i = 1; i <= m; i ++) {
        for(int j = 1; j <= n; j ++) {
            char x;
            cin >> x;
            g[i][j] = x - '0';
        }
        char x;
        cin >> x;
        g[i][n + 1] = x - '0';
    }

    bitset<N> ans;
    auto check = [&](int x) {
        auto [f, res] = guass(x, n, g);
        if(f == 1) {
            ans = res;
            return true;
        }
        return false;
    };

    int l = n, r = m + 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if(l <= m) {
        cout << l << '\n';
        for(int i = 1; i <= n; i ++) {
            if(ans[i]) {
                cout << "?y7M#" << '\n';
            } else {
                cout << "Earth" << '\n';
            }
        }
    } else {
        cout << "Cannot Determine" << '\n';
    }
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