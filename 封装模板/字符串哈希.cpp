#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
使用前需根据最大可能的字符串长度进行init_static初始化
*/
using i64 = long long;

struct strHash {
    // 被卡可以换成大素数如 1000000000039
    static constexpr i64 mod = 1e9 + 7;

    inline static i64 base = 0;
    inline static vector<i64> p;

    vector<i64> h;
    int n;

    strHash() : n(0) {
        h = {0}; 
    }

    strHash(const string& s) {
        init(s);
    }

    // 必须在程序开头调用一次进行初始化
    static void init_static(int mx) {
        if(base != 0) {
            return;
        }
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        base = rng() % 500 + 131;

        p.resize(mx + 1);
        p[0] = 1;
        for(int i = 1; i <= mx; i ++) {
            p[i] = p[i - 1] * base % mod;
        }
    }

    void init(const string &s) {
        assert(base != 0);
        n = s.size();
        h.assign(n + 1, 0);
        for(int i = 1; i <= n; i ++) {
            h[i] = (h[i - 1] * base + s[i - 1]) % mod;
        }
    }

    i64 get() const {
        return h.back();
    }

    i64 get(int l, int r) const {
        if(l == 1 && r == n) {
            return get();
        }
        if(l > r) {
            return 0;
        }
        return (h[r] - h[l - 1] * p[r - l + 1] % mod + mod) % mod;
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
        h.emplace_back((h.back() * base + c) % mod); 
        return *this;
    }

    strHash& operator+=(const string &s) {
        if(s.empty()) {
            return *this;
        }
        for(auto c : s) {
            n ++;
            h.emplace_back((h.back() * base + c) % mod); 
        }
        return *this;
    }

    bool operator==(const strHash &ano) const {
        if(n != ano.n) {
            return false;
        }
        return h.back() == ano.h.back();
    }

    // 切片结构类，用于取切片并连接
    struct sub {
        const strHash *ptr;
        int l, r;

        i64 get() const {
            return ptr->get(l, r);
        }
        int len() const {
            return r - l + 1;
        }

        friend i64 operator+(const sub &a, const sub &b) {
            int len = b.len();
            return (a.get() * p[len] + b.get()) % mod;
        }

        friend i64 operator+(const sub &a, char c) {
            return (a.get() * base + c) % mod;
        }

        friend i64 operator+(const sub &a, const string &s) {
            i64 ha = a.get();
            int len = s.size();
            i64 sh = 0;
            for(auto c : s) {
                sh = (sh * base + c) % mod;
            }
            return (ha * p[len] + sh) % mod;
        }
    };

    sub operator()(int l, int r) const {
        return {this, l, r};
    }
    sub all() const {
        return {this, 1, n};
    }
};

void solve() {
    strHash::init_static(1500);
    int n;
    cin >> n;
    vector<strHash> hs(n);
    vector<i64> res(n);
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        hs[i].init(s);
        res[i] = hs[i].get();
    }

    cout << hs[0].get() << ' ' << hs[2].get() << '\n';

    res.erase(unique(res.begin(), res.end()), res.end());
    cout << res.size() << '\n';
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --) {
        solve();
    }
    return 0;
}