#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
(()())
*/

struct DSU {
    vector<int> p, siz;

    DSU(int n = 0) {
        init(n);
    }

    void init(int n) {
        p.resize(n + 1); 
        iota(p.begin(), p.end(), 0);
        siz.assign(n + 1, 1);
    }

    int find(int x) {
        if(x != p[x]) p[x] = find(p[x]);
        return p[x];
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        p[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[find(x)];
    }
};

const int mod = 998244353;

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
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
    int n;
    cin >> n;
    string s;
    cin >> s;

    DSU dsu(n);
    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '(') {
            stk.emplace_back(i);
        } else {
            int t = stk.back();
            stk.pop_back();
            dsu.merge(t, i);
        }
    }

    for(int i = 0; i < n; i ++) {
        if(i != 0 && s[i] == s[i - 1]) {
            dsu.merge(i, i - 1);
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(dsu.find(i) == i) {
            cnt ++;
        }
    }

    cout << qmi(2, cnt) << '\n';
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
