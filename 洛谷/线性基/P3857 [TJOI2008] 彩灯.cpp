#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

const int mod = 2008;

template<class T>
struct LinearBasis {
    // 根据数据最高位修改
    const int N = 50;
    vector<T> b, g;

    int sz = 0;
    bool zero = false;
    bool dirty = true;
    LinearBasis() : b(N + 1) {};

    bool insert(T x) {
        dirty = true;
        for(int i = N; i >= 0; i --) {
            if(x >> i & 1) {
                if(b[i]) {
                    x ^= b[i];
                } else {
                    b[i] = x;
                    sz ++;
                    return true;
                }
            }
        }
        zero = true;
        return false;
    }

    T queryMax(T x = 0) {
        for(int i = N; i >= 0; i --) {
            if(b[i] && ~x >> i & 1) {
                x ^= b[i];
            }
        }
        return x;
    }

    T queryMin(T x = 0) {
        for(int i = N; i >= 0; i --) {
            if(b[i] && x >> i & 1) {
                x ^= b[i];
            }
        }
        return x;
    }

    T count() {
        return (1ll << sz);
    }

    void gauss() {
        if(!dirty) {
            return;
        }

        g.clear();
        for(int i = N; i >= 0; i --) {
            if(!b[i]) {
                continue;
            }
            for(int j = i + 1; j <= N; j ++) {
                if(b[j] >> i & 1) {
                    b[j] ^= b[i];
                }
            }
        }

        for(int i = 0; i <= N; i ++) {
            if(b[i]) {
                g.emplace_back(b[i]);
            }
        }

        dirty = false;
    }

    T kth(T k) {
        gauss();
        k -= zero;
        if(!k) {
            return 0;
        }
        if(k >= (1ll << g.size())) {
            return -1;
        }

        T res = 0;
        for(int i = 0; i < g.size(); i ++) {
            if(k >> i & 1) {
                res ^= g[i];
            }
        }
        return res;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    LinearBasis<i64> lb;

    vector<i64> p2(n + 1);
    p2[0] = 1;
    for(int i = 1; i <= n; i ++) {
        p2[i] = p2[i - 1] * 2;
    }

    for(int i = 0; i < m; i ++) {
        string s;
        cin >> s;
        i64 x = 0;
        for(int i = 0; i < s.size(); i ++) {
            if(s[i] == 'O') {
                x += p2[i];
            }
        }
        lb.insert(x);
    }

    cout << lb.count() % mod << '\n';
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