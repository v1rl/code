#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u128 = unsigned __int128;

struct strHash {
    static constexpr u64 mod = (1ULL << 61) - 1;

    inline static u64 base = 0;
    inline static vector<u64> p;

    vector<u64> h;
    int n;

    strHash() : n(0) {
        h = {0}; 
    }

    strHash(const string& s) {
        init(s);
    }

    static inline u64 add(u64 a, u64 b) {
        a += b;
        if (a >= mod) a -= mod;
        return a;
    }

    static inline u64 sub(u64 a, u64 b) {
        return (a >= b) ? a - b : a + mod - b;
    }

    static inline u64 mul(u64 a, u64 b) {
        u128 c = (u128)a * b;
        u64 res = (u64)(c >> 61) + (u64)(c & mod);
        if (res >= mod) res -= mod;
        return res;
    }

    // 必须在程序开头调用一次进行初始化
    static void init_static(int mx) {
        if(base != 0) {
            return;
        }
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        base = rng() % (mod - 131) + 131;

        p.resize(mx + 1);
        p[0] = 1;
        for(int i = 1; i <= mx; i ++) {
            p[i] = mul(p[i - 1], base);
        }
    }

    void init(const string &s) {
        assert(base != 0);
        n = s.size();
        h.assign(n + 1, 0);
        for(int i = 1; i <= n; i ++) {
            h[i] = add(mul(h[i - 1], base), s[i - 1]);
        }
    }

    u64 get() const {
        return h.back();
    }

    u64 get(int l, int r) const {
        if(l == 1 && r == n) {
            return get();
        }
        if(l > r) {
            return 0;
        }
        return sub(h[r], mul(h[l - 1], p[r - l + 1]));
    }

    int getLCP(int l1, int r1, int l2, int r2) const {
        int len = min(r1 - l1, r2 - l2) + 1;
        int l = 0, r = len;
        while(l < r) {
            int mid = (l + r + 1) >> 1;
            if(get(l1, l1 + mid - 1) == get(l2, l2 + mid - 1)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }

    strHash& operator+=(char c) {
        n ++;
        h.emplace_back(add(mul(get(), base), c)); 
        return *this;
    }

    strHash& operator+=(const string &s) {
        if(s.empty()) {
            return *this;
        }
        for(auto c : s) {
            n ++;
            h.emplace_back(add(mul(get(), base), c)); 
        }
        return *this;
    }

    bool operator==(const strHash &ano) const {
        if(n != ano.n) {
            return false;
        }
        return get() == ano.get();
    }

    // 切片结构类，用于取切片并连接
    struct Sub {
        const strHash *ptr;
        int l, r;

        u64 get() const {
            return ptr->get(l, r);
        }
        int len() const {
            return r - l + 1;
        }

        friend u64 operator+(const Sub &a, const Sub &b) {
            int len = b.len();
            return add(mul(a.get(), p[len]), b.get());
        }

        friend u64 operator+(const Sub &a, char c) {
            return add(mul(a.get(), base), c);
        }

        friend u64 operator+(const Sub &a, const string &s) {
            u64 ha = a.get();
            int len = s.size();
            u64 sh = 0;
            for(auto c : s) {
                sh = add(mul(sh, base), c);
            }
            return add(mul(ha, p[len]), sh);
        }
    };

    Sub operator()(int l, int r) const {
        return {this, l, r};
    }
    Sub all() const {
        return {this, 1, n};
    }
};

typedef pair<string, strHash> PSH;

void solve() {
    strHash::init_static(1000000);
    int n;
    cin >> n;
    vector<PSH> s(n);

    for(int i = 0; i < n; i ++) {
        cin >> s[i].first;
        s[i].second = strHash(s[i].first);
    }

    sort(s.begin(), s.end(), 
        [&](const auto &x, const auto &y) {
            auto &[sx, hx] = x;
            auto &[sy, hy] = y;
            int xS = hx.n, yS = hy.n;

            int l = 0, r = xS + yS;
            while(l < r) {
                int mid = l + r + 1 >> 1;
                u64 lh, rh;
                if(mid <= xS) {
                    lh = hx.get(1, mid);
                } else {
                    lh = hx.all() + hy(1, mid - xS);
                }
                if(mid <= yS) {
                    rh = hy.get(1, mid);
                } else {
                    rh = hy.all() + hx(1, mid - yS);
                }

                if(lh == rh) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }

            if(l == xS + yS) {
                return false;
            }
            char X = (l >= xS ? sy[l - xS] : sx[l]);
            char Y = (l >= yS ? sx[l - yS] : sy[l]);
            return X < Y;
        });

    if(n == 2) {
        cout << s[1].first + s[0].first << '\n';
        return;
    }

    for(int i = 0; i < n - 1; i ++) {
        if(s[i].second.all() + s[i + 1].second.all() == s[i + 1].second.all() + s[i].second.all()) {
            for(auto &c : s) {
                cout << c.first;
            }
            cout << '\n';
            return;
        }
    }

    string ans1, ans2;
    swap(s[n - 1], s[n - 2]);
    for(auto &c : s) {
        ans1 += c.first;
    }
    swap(s[n - 1], s[n - 2]);
    swap(s[n - 2], s[n - 3]);
    for(auto &c : s) {
        ans2 += c.first;
    }
    cout << min(ans1, ans2) << '\n';
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
