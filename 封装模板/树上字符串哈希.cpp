#include <bits/stdc++.h>
using namespace std;

/*
使用前需根据最大可能的字符串长度进行init_hash初始化
维护当前点向上2的i次方个点（不包括当前点）的哈希值stup
维护向下2的i次方恰到达当前点（不包括当前点）的哈希值stdown
不包括当前点是为了左闭右开更好地维护
*/

using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

constexpr u64 mod = (1ULL << 61) - 1;
u64 add(u64 a, u64 b) {
    a += b;
    if (a >= mod) a -= mod;
    return a;
}

u64 sub(u64 a, u64 b) {
    return (a >= b) ? a - b : a + mod - b;
}

u64 mul(u64 a, u64 b) {
    u128 c = (u128)a * b;
    u64 res = (u64)(c >> 61) + (u64)(c & mod);
    if (res >= mod) res -= mod;
    return res;
}

vector<u64> p;
void init_hash(int n) {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    u64 base = rng() % (mod - 131) + 131;
    p.resize(n + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i ++) {
        p[i] = mul(p[i - 1], base);
    }
}

const int N = 18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> adj(n + 1);
    for(int y = 1; y <= n; y ++) {
        int x;
        cin >> x;
        if(y == 1) {
            continue;
        }
        adj[x].emplace_back(y);
    }

    init_hash(100000);

    vector<array<u64, N>> stup(n + 1);
    vector<array<u64, N>> stdown(n + 1);
    vector<array<int, N>> f(n + 1);
    queue<int> q;
    q.push(1);
    vector<int> dep(n + 1);
    dep[1] = 1;
    while(q.size()) {
        int x = q.front();
        q.pop();

        for(auto y : adj[x]) {
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            stup[y][0] = s[x - 1];
            stdown[y][0] = s[x - 1];
            for(int i = 1; i < N; i ++) {
                // 注意方向不同导致的运算差别
                f[y][i] = f[f[y][i - 1]][i - 1];
                stup[y][i] = add(mul(stup[y][i - 1], p[1 << i - 1]), stup[f[y][i - 1]][i - 1]);
                stdown[y][i] = add(mul(stdown[f[y][i - 1]][i - 1], p[1 << i - 1]), stdown[y][i - 1]);
            }
            q.push(y);
        }
    }

    auto lca = [&](int x, int y) {
        if(dep[y] > dep[x]) {
            swap(x, y);
        }
        for(int i = N - 1; i >= 0; i --) {
            if(dep[f[x][i]] >= dep[y]) {
                x = f[x][i];
            }
        }
        if(x == y) {
            return x;
        }
        for(int i = N - 1; i >= 0; i --) {
            if(f[x][i] != f[y][i]) {
                x = f[x][i], y = f[y][i];
            }
        }
        return f[x][0];
    };

    auto get = [&](int x, int y, int P) -> u64 {
        u64 pre = s[x - 1];
        for(int i = N - 1; i >= 0; i --) {
            if(dep[f[x][i]] >= dep[P]) {
                pre = add(mul(pre, p[1 << i]), stup[x][i]);
                x = f[x][i];
            }
        }

        // 注意特判返回
        if(y == P) {
            return pre;
        }

        u64 suf = s[y - 1];
        int res = 1;
        for(int i = N - 1; i >= 0; i --) {
            // 注意不要重复计算P点
            if(dep[f[y][i]] > dep[P]) {
                // 注意向下时的计算顺序，需要维护当前已经有多少个点res
                suf = add(mul(stdown[y][i], p[res]), suf);
                y = f[y][i];
                res += 1 << i;
            }
        }

        return add(mul(pre, p[res]), suf);
    };

    int m;
    cin >> m;
    while(m --) {
        int x, y;
        cin >> x >> y;
        int P = lca(x, y);

        if(get(x, y, P) == get(y, x, P)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}