#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

template<class T>
struct LinearBasis {
    // 根据数据最高位修改
    const int N = 62;
    vector<T> b, g;

    int sz = 0;
    bool zero = false;
    bool dirty = true;
    LinearBasis() : b(N + 1) {};

    bool insert(T x) {
        dirty = true;
        for(int i = N; i >= 0; i --) {
            if(x >> i & 1) {
                if(!b[i]) {
                    b[i] = x;
                    sz ++;
                    return true;
                } else {
                    x ^= b[i];
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
        return (1ll << sz) - 1 + zero;
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
    int n;
    cin >> n;
    vector<array<i64, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][1] >> a[i][0];
    }

    LinearBasis<i64> lb;
    sort(a.begin(), a.end(), greater());
    i64 ans = 0;
    for(auto &[v, x] : a) {
        if(lb.insert(x)) {
            ans += v;
        }
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