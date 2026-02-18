#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

struct DSU {
    vector<int> p, siz;

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1); 
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

template <int mod>
struct Mint {
    u32 x;
    Mint() : x(0) {}
    // 构造读入的数不能是负数，不能大于mod
    Mint(u32 x) : x(x) {}
    static u32 down(u32 x) {
        return x >= mod ? x - mod : x;
    }

    friend Mint operator+(Mint a, Mint b) { return down(a.x + b.x); }
    friend Mint operator-(Mint a, Mint b) { return down(a.x - b.x + mod); }
    friend Mint operator*(Mint a, Mint b) { return 1ULL * a.x * b.x % mod; }
    friend Mint operator/(Mint a, Mint b) { return a * inv(b); }

    friend Mint operator-(Mint a) { return down(mod - a.x); }

    static Mint qmi(Mint a, i64 b) {
        Mint ans = 1;
        while (b) {
            if (b & 1) ans = ans * a;
            a = a * a;
            b /= 2;
        }
        return ans;
    }

    static Mint inv(Mint a) { return qmi(a, (mod - 2)); }
    // static Mint inv(Mint a) {
    //     auto [g, v] = invGcd(a.x, mod);
    //     assert(g == 1);
    //     return (u32)v;
    // }

    friend std::istream &operator>>(std::istream &in, Mint &a) { return in >> a.x; }
    friend std::ostream &operator<<(std::ostream &out, Mint a) { return out << a.x; }

    friend Mint &operator+=(Mint &a, Mint b) { return a = a + b; }
    friend Mint &operator-=(Mint &a, Mint b) { return a = a - b; }
    friend Mint &operator*=(Mint &a, Mint b) { return a = a * b; }
    friend Mint &operator/=(Mint &a, Mint b) { return a = a / b; }

    friend bool operator==(Mint a, Mint b) { return a.x == b.x; }
    friend bool operator!=(Mint a, Mint b) { return !(a == b); }
    friend bool operator<(Mint a, Mint b) { return a.x < b.x; }
};

const int mod = 998244353;
using Z = Mint<mod>;

void solve() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n + 1);
    vector<vector<array<int, 2>>> info(n + 1);
    vector<int> L(n + 1), R(n + 1, n);
    for(int i = 0; i < m; i ++) {
        int l, r, v;
        cin >> l >> r >> v;
        L[v] = max(L[v], l);
        R[v] = min(R[v], r);
        info[v].push_back({l, r});
    }


    vector<int> U(n + 1);
    vector<int> free(n + 1);
    vector<int> cnt(n + 1);
    for(int v = 1; v <= n; v ++) {
        for(auto [l, r] : info[v]) {
            for(int j = dsu.find(l); j <= r; j = dsu.find(j)) {
                U[j] = v;
                cnt[v] ++;
                if(j >= L[v] && j <= R[v]) {
                    free[v] ++;
                }
                dsu.merge(j + 1, j);
            }
        }
    }

    int cur = 0;
    for(int i = 1; i <= n; i ++) {
        if(!U[i]) {
            cur ++;
        }
    }

    Z ans = 1;
    for(int v = n; v >= 1; v --) {
        cur += cnt[v];
        if(info[v].empty()) {
            ans *= cur;
        } else {
            ans *= free[v];
        }
        cur --;
    }

    cout << ans << '\n';
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
