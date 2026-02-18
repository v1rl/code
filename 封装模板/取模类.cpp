#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;

i64 safeMod(i64 x, i64 m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

pair<i64, i64> invGcd(i64 a, i64 b) {
    a = safeMod(a, b);
    if(a == 0) {
        return {b, 0};
    }

    i64 s = b, t = a;
    i64 m0 = 0, m1 = 1;

    while (t) {
        i64 u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        std::swap(s, t);
        std::swap(m0, m1);
    }

    if(m0 < 0) {
        m0 += b / s;
    }
    return {s, m0};
}

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
    // vector<Z> a(2);
    // cin >> a[0] >> a[1];
    // cout << Z::inv(a[0] + a[1]) << '\n';
    Z ans(1);
    ans *= 100;
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
