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

    bool has(T x) {
        if(x == 0) {
            return zero;
        }
        for(int i = N; i >= 0; i --) {
            if(x >> i & 1) {
                x ^= b[i];
            }
        }
        return x == 0;
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
        if(x == 0) {
            if(zero) {
                return 0;
            }
            for(int i = 0; i <= N; i ++) {
                if(b[i]) {
                    return b[i];
                }
            }
        } else {
            for(int i = N; i >= 0; i --) {
                if(b[i] && x >> i & 1) {
                    x ^= b[i];
                }
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
        if(k >= ((T)1 << g.size())) {
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

const int mod = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    LinearBasis<i64> lb;
    for(int i = 1; i <= n; i ++) {
        i64 x;
        cin >> x;
        lb.insert(x);
    }
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