#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

// https://codeforces.com/problemset/problem/896/C

struct Node {
    int l, r;
    mutable i64 v;

    bool operator <(const Node &ano) const {
        return l < ano.l;
    }
};

const int mod = 1e9 + 7;

int seed, vm;
int rnd() {
    int ret = seed;
    seed = (1ll * seed * 7 + 13) % mod;
    return ret;
}

i64 qmi(i64 a, i64 b, int mod) {
    i64 res = 1;
    a %= mod;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m >> seed >> vm;
    set<Node> odt;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        a[i] = rnd() % vm + 1;
        odt.insert({i, i + 1, a[i]});
    }

    auto split = [&](int x) {
        auto it = odt.lower_bound({x, 0, 0});
        if(it != odt.end() && it->l == x) {
            return it;
        }
        it --;
        auto [l, r, v] = *it;
        odt.erase(it);
        odt.insert({l, x, v});
        return odt.insert({x, r, v}).first;
    };

    auto assign = [&](int l, int r, int x) {
        auto itr = split(r + 1);
        auto itl = split(l);
        odt.erase(itl, itr);
        odt.insert({l, r + 1, x});
    };

    auto add = [&](int l, int r, int x) {
        auto itr = split(r + 1);
        auto itl = split(l);
        for(auto it = itl; it != itr; it ++) {
            it->v += x;
        }
    };

    auto kth = [&](int l, int r, int x) -> i64 {
        auto itr = split(r + 1);
        auto itl = split(l);
        vector<array<i64, 2>> vec;
        for(auto it = itl; it != itr; it ++) {
            vec.push_back({it->v, it->r - it->l});
        }
        sort(vec.begin(), vec.end());
        for(auto [v, num] : vec) {
            x -= num;
            if(x <= 0) {
                return v;
            }
        }
        return -1;
    };

    auto query = [&](int l, int r, int x, int y) {
        auto itr = split(r + 1);
        auto itl = split(l);
        int res = 0;
        for(auto it = itl; it != itr; it ++) {
            res = (res + 1ll * qmi(it->v, x, y) * (it->r - it->l) % y) % y;
        }
        return res;
    };


    for(int i = 1; i <= m; i ++) {
        int op = rnd() % 4 + 1;
        int l = rnd() % n + 1;
        int r = rnd() % n + 1; 
        if(l > r) {
            swap(l, r);
        }
        int x, y; 
        if(op == 3) {
            x = rnd() % (r - l + 1) + 1;
        } else {
            x = rnd() % vm + 1;
        }
        if(op == 4) {
            y = rnd() % vm + 1;
        }

        if(op == 1) {
            add(l, r, x);
        } else if(op == 2) {
            assign(l, r, x);
        } else if(op == 3) {
            cout << kth(l, r, x) << '\n';
        } else {
            cout << query(l, r, x, y) << '\n';
        }
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
