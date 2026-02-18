#include<bits/stdc++.h>
using namespace std;
using u32 = unsigned;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

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

const int mod = 1e9 + 7;
using Z = Mint<mod>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[x] = i;
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    vector<Z> dp(n + 1);
    vector<int> p(n + 1);
    auto dfs = [&](auto &&self, int x) -> void {
        dp[x] = 1;
        for(auto y : adj[x]) {
            if(y == p[x]) {
                continue;
            }
            p[y] = x;
            self(self, y);
            dp[x] *= dp[y];
        }
        dp[x] += 1;
    };

    dfs(dfs, a[0]);

    Z ans = 0, res = 1;
    int pw = 0;
    auto mul = [&](Z x) {
        if(x == 0) {
            pw ++;
        } else {
            res *= x;
        }
    };

    auto div = [&](Z x) {
        if(x == 0) {
            pw --;
        } else {
            res /= x;
        }
    };

    mul(dp[a[0]]);
    vector<int> vis(n + 1);
    for(auto x : a) {
        while(x >= 1 && !vis[x]) {
            vis[x] = true;
            div(dp[x]);
            mul(dp[x] - 1);
            // for(auto y : adj[x]) {
            //     if(y == p[x]) {
            //         continue;
            //     }
            //     mul(dp[y]);
            // }
            x = p[x];
        }

        if(pw == 0) {
            ans += res;
        }
    }

    cout << ans << '\n';
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