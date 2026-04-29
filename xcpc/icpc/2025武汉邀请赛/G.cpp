#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

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

    friend istream &operator>>(istream &in, Mint &a) { return in >> a.x; }
    friend ostream &operator<<(ostream &out, Mint a) { return out << a.x; }

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

vector<Z> fact, infact;
void init(int n) {
    fact.resize(n + 1);
    infact.resize(n + 1);

    fact[0] = infact[0] = fact[1] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = fact[i - 1] * i;
        infact[i] = (mod - mod / i) * infact[mod % i];
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = infact[i - 1] * infact[i];
    }
}

Z C(i64 a, i64 b) {
    if(a < b) {
        return 0;
    }
    return fact[a] * infact[b] * infact[a - b];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> vec(n * m + 1);
    vector g(n + 1, vector(m + 1, 0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            cin >> g[i][j];
            vec[g[i][j]].push_back({i, j});
        }
    }

    auto get = [&](int x, int y) {
        return C(x + y, x);
    };

    int B = sqrt(n * m);
    Z ans = 0;
    for(int v = 1; v <= n * m; v ++) {
        int M = vec[v].size();
        if(M == 0) {
            continue;
        }
        if(M <= B) {
            auto &a = vec[v];
            vector<Z> f(M);
            for(int i = 0; i < M; i ++) {
                auto [x, y] = a[i];
                f[i] = get(x - 1, y - 1);
                for(int j = 0; j < i; j ++) {
                    f[i] -= f[j] * get(x - a[j][0], y - a[j][1]);
                }
                ans += f[i] * get(n - x, m - y);
            }
        } else {
            vector f(n + 1, vector(m + 1, (Z)0));
            f[0][1] = 1;
            for(int i = 1; i <= n; i ++) {
                for(int j = 1; j <= m; j ++) {
                    if(g[i][j] != v) {
                        f[i][j] = f[i - 1][j] + f[i][j - 1];
                    }
                }
            }
            for(auto [x, y] : vec[v]) {
                ans += (f[x - 1][y] + f[x][y - 1]) * get(n - x, m - y);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    init(100000);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
