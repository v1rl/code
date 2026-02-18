#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
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

const int inf = 1e9 + 10;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    vector<i64> a(n + 1), b(m + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for(int i = 1; i <= m; i ++) {
        cin >> b[i];
    }

    int cur = 0;
    i64 pos = 0;

    for(int i = 1; i <= m; i ++) {
        if(a[cur + 1] < pos + l) {
            // cerr << cur + 1 << ' ' << a[cur + 1] << ' ' << pos + l << '\n';
            cout << "YES" << '\n';
            return;
        }

        pos += b[i];
        while(cur + 1 <= n && a[cur + 1] <= pos) {
            cur ++;
        }

        if(cur == n) {
            cout << "NO" << '\n';
            return;
        }
    }

    if(a[cur + 1] < pos + l) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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