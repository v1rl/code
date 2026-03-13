#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;

/*
使用前需根据最大可能的字符串长度进行init_static初始化
*/
using i64 = long long;

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

Z P = 3;
Z invP = Z(1) / P;

void dft(vector<Z> &a, int op) {
    int n = a.size();

    vector<int> rev(n);
    for(int i = 0; i < n; i ++) {
        rev[i] = rev[i >> 1] >> 1 | ((i & 1) ? (n >> 1) : 0);
    }
    for(int i = 0; i < n; i ++) {
        if(i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }

    for(int k = 1; k < n; k <<= 1) {
        Z g1 = Z::qmi(op == 1 ? P : invP, (mod - 1) / (k * 2));
        for(int i = 0; i < n; i += k * 2) {
            Z gk = 1;
            for(int j = 0; j < k; j ++) {
                Z x = a[i + j];
                Z y = a[i + j + k] * gk;
                a[i + j] = x + y;
                a[i + j + k] = x - y;
                gk *= g1;
            }
        }
    }
}

void NTT(vector<Z> &a, vector<Z> &b) {
    int n = 1, tot = a.size() + b.size() - 1;
    while(n < tot) {
        n <<= 1;
    }

    a.resize(n), b.resize(n);
    dft(a, 1), dft(b, 1);
    for(int i = 0; i < n; i ++) {
        a[i] *= b[i];
    }
    dft(a, -1);

    a.resize(tot);
    Z inv = Z(1) / n;
    for(int i = 0; i < tot; i ++) {
        a[i] *= inv;
    }
}

void solve() {
    // i + d, i
    // n - 1 - i - d, i
    // k = n - 1 - d
    // d = n - 1 - k
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    reverse(s.begin(), s.end());

    vector<int> nums(n);

    char ch[] = {'A', 'T', 'C', 'G'};
    for(int x = 0; x < 4; x ++) {
        vector<Z> f(n), g(m);
        for(int i = 0; i < n; i ++) {
            f[i] = s[i] == ch[x];
        }
        for(int i = 0; i < m; i ++) {
            g[i] = t[i] == ch[x];
        }

        NTT(f, g);
        for(int i = 0; i < f.size(); i ++) {
            int d = (n - 1 - i + n) % n;
            nums[d] += f[i].x;
        }
    }

    int ans = 0;
    for(int i = 0; i <= n - m; i ++) {
        if(nums[i] >= m - 3) {
            ans ++;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}