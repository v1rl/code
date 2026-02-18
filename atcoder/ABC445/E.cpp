#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    const int N = 1e7 + 10;
    vector<unordered_map<int, int>> suf(n + 2);

    unordered_map<int, int> pre;

    auto divide = [&](int x, int cur) {
        vector<int> b;
        suf[cur] = suf[cur + 1];
        unordered_map<int, int> mp;

        for(int i = 2; i <= x / i; i ++) {
            if(x % i == 0) {
                b.emplace_back(i);
                while(x % i == 0) {
                    mp[i] ++;
                    x /= i;
                }
            }
            if(x > 1) {
                b.emplace_back(i);
                mp[x] ++;
            }
        }

        for(auto c : b) {
            suf[cur][c] = max(suf[cur][c], mp[c]);
        }
    };

    auto dividep = [&](int x) {
        vector<int> b;
        unordered_map<int, int> mp;

        for(int i = 2; i <= x / i; i ++) {
            if(x % i == 0) {
                b.emplace_back(i);
                while(x % i == 0) {
                    mp[i] ++;
                    x /= i;
                }
            }
            if(x > 1) {
                b.emplace_back(i);
                mp[x] ++;
            }
        }

        for(auto c : b) {
            pre[c] = max(pre[c], mp[c]);
        }
    };

    Z ans = 0;
    for(int i = 1; i < N; i ++) {
        
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}