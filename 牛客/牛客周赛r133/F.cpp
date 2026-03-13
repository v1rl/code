#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;
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

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    vector<int> d(n + 1);
    for(int i = 1; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
        d[x] ++, d[y] ++;
    }

    vector<int> cnt(n + 1);
    for(int x = 1; x <= n; x ++) {
        if(d[x] > 1) {
            for(auto y : adj[x]) {
                cnt[y] ++;
            }
        }
    }

    Z ans = 0;
    for(int x = 1; x <= n; x ++) {
        if(d[x] == n - 1) {
            continue;
        }

        Z res = 1;
        res /= n;
        for(auto y : adj[x]) {
            if(d[y] == 1) {
                ;
            } else if(d[y] == 2) {
                int z = adj[y][0];
                if(z == x) {
                    z = adj[y][1];
                }
                
                if(d[z] == 1) {
                    ;
                } else if(cnt[z] == 1) {
                    res /= (d[z] + 1);
                } else {
                    res = 0;
                }
            } else {
                int ls = (d[x] > 1);
                if(cnt[y] == ls) {
                    res /= d[y];
                } else {
                    res = 0;
                }
            }

            if(res == 0) {
                break;
            }
        }

        ans += res;
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
