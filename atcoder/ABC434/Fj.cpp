#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

typedef pair<int, int> PII;

struct strHash {
    static constexpr i64 mod1 = 1e9 + 7;
    static constexpr i64 mod2 = 1e9 + 9;

    inline static i64 base1 = 0, base2 = 0;
    inline static vector<i64> p1, p2;

    vector<i64> h1, h2;
    int n;

    strHash() : n(0) {
        h1 = {0}; 
        h2 = {0};
    }

    strHash(string s) {
        init(s);
    }

    static void init_static(int mx) {
        if(base1 != 0) {
            return;
        }
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        base1 = rng() % 500 + 131;
        base2 = rng() % 500 + 13331;

        p1.resize(mx + 1), p2.resize(mx + 1);
        p1[0] = 1, p2[0] = 1;
        for(int i = 1; i <= mx; i ++) {
            p1[i] = p1[i - 1] * base1 % mod1;
            p2[i] = p2[i - 1] * base2 % mod2;
        }
    }

    void init(const string &s) {
        assert(base1 != 0);
        n = s.size();
        h1.assign(n + 1, 0), h2.assign(n + 1, 0);
        for(int i = 1; i <= n; i ++) {
            h1[i] = (h1[i - 1] * base1 + s[i - 1]) % mod1;
            h2[i] = (h2[i - 1] * base2 + s[i - 1]) % mod2;
        }
    }

    PII get() const {
        return {h1.back(), h2.back()};
    }

    PII get(int l, int r) const {
        if(l == 1 && r == n) {
            return get();
        }
        if(l > r) {
            return {0, 0};
        }

        i64 v1 = (h1[r] - h1[l - 1] * p1[r - l + 1] % mod1 + mod1) % mod1;
        i64 v2 = (h2[r] - h2[l - 1] * p2[r - l + 1] % mod2 + mod2) % mod2;
        return {v1, v2};
    }


    int getLCP(int l1, int r1, int l2, int r2) {
        int len = min(r1 - l1, r2 - l2) + 1;

        int l = 0, r = len;
        while(l < r) {
            int mid = l + r + 1 >> 1;
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
        h1.emplace_back((h1.back() * base1 + c) % mod1); 
        h2.emplace_back((h2.back() * base2 + c) % mod2);
        return *this;
    }

    strHash& operator+=(const string &s) {
        if(s.empty()) {
            return *this;
        }
        for(auto c : s) {
            n ++;
            h1.emplace_back((h1.back() * base1 + c) % mod1); 
            h2.emplace_back((h2.back() * base2 + c) % mod2);
        }
        return *this;
    }

    bool operator==(const strHash &ano) const {
        if(n != ano.n) {
            return false;
        }
        return h1.back() == ano.h1.back() && h2.back() == ano.h2.back();
    }

    struct sub {
        const strHash *ptr;
        int l, r;

        PII get() const {
            return ptr->get(l, r);
        }
        int len() const {
            return r - l + 1;
        }

        friend PII operator+(const sub &a, const sub &b) {
            int len = b.len();
            PII ha = a.get(), hb = b.get();
            return {(ha.first * p1[len] + hb.first) % mod1, (ha.second * p2[len] + hb.second) % mod2};
        }

        friend PII operator+(const sub &a, char c) {
            PII ha = a.get();
            return {(ha.first * base1 + c) % mod1, (ha.second * base2 + c) % mod2};
        }

        friend PII operator+(const sub &a, const string &s) {
            PII ha = a.get();
            int len = s.size();
            i64 sh1 = 0, sh2 = 0;
            for(auto c : s) {
                sh1 = (sh1 * base1 + c) % mod1;
                sh2 = (sh2 * base2 + c) % mod2;
            }
            return {(ha.first * p1[len] + sh1) % mod1, (ha.second * p2[len] + sh2) % mod2};
        }
    };

    sub operator()(int l, int r) const {
        return {this, l, r};
    }
    sub all() const {
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
                PII lh, rh;
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
