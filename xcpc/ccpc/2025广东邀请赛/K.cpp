#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

vector<int> manacher(string &s) {
    string t = "#";
    for(auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for(int i = 0, j = 0; i < n; i ++) {
        if(j + r[j] > i) {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while(i - r[i] >= 0 && i + r[i] < n && t[i + r[i]] == t[i - r[i]]) {
            r[i] ++;
        }
        if(i + r[i] > j + r[j]) {
            j = i;
        }
    }

    return r;
}

vector<int> zFunction(string &s) {
    int n = s.size();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i ++) {
        if(i <= r) {
            z[i] = min(z[i - l], r - i + 1);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i] ++;
        }
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

struct DSU {
    vector<int> p;

    DSU(int n) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x) {
        if(x != p[x]) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) {
            return false;
        }
        p[y] = x;
        return true;
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    auto z = zFunction(s);
    auto mch = manacher(s);
    DSU dsu(n);

    vector<int> rad;
    for(int i = 1; i < mch.size(); i += 2) {
        rad.emplace_back(mch[i] / 2);
    }

    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);

    auto assign = [&](int l, int r, int v) {
        for(int i = dsu.find(l); i <= r; i = dsu.find(i)) {
            ans[i] = v;
            dsu.merge(i + 1, i);
        }
    };

    for(int len = 1; len <= n; len ++) {
        if(len == 1) {
            if(n > 1) {
                assign(0, z[1], len);
            } else {
                assign(0, 0, len);
            }
            continue;
        }

        int mid = len - 1;
        assign(mid, mid + rad[mid] - 1, len);

        int T = len * 2 - 2;
        if(T < n && rad[mid] == mid + 1) {
            assign(T - 1, T + z[T] - 1, len);
        }
    }

    i64 res = 0;
    for(int i = 0; i < n; i ++) {
        res ^= 1ll * (i + 1) * ans[i];
    }

    cout << res << '\n';
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
