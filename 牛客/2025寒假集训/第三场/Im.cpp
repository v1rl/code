#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

template<class T>
struct LinearBasis {
    const int N = 29;
    vector<T> b, g;
    
    vector<T> set;
    vector<int> id;

    int sz = 0;
    bool zero = false;
    bool dirty = true;
    LinearBasis() : b(N + 1), set(N + 1) {};

    bool insert(T x, int cid) {
        dirty = true;
        int s = 0;
        for(int i = N; i >= 0; i --) {
            if(x >> i & 1) {
                if(b[i]) {
                    x ^= b[i];
                    s ^= set[i];
                } else {
                    b[i] = x;
                    set[i] = s ^ (1 << id.size());
                    id.emplace_back(cid);
                    sz ++;
                    return true;
                }
            }
        }
        zero = true;
        return false;
    }

    bool has(T x, auto &a, auto &bb) {
        int s = 0;
        for(int i = N; i >= 0; i --) {
            if(x >> i & 1) {
                x ^= b[i];
                s ^= set[i];
            }
        }
        for(int i = N; i >= 0; i --) {
            if(s >> i & 1) {
                a[id[i]] = bb[id[i]];
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
    vector<int> a(n), b(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }

    LinearBasis<int> lb;
    for(int i = 0; i < n; i ++) {
        int x = a[i] ^ b[i];
        lb.insert(x, i);
    }

    if(lb.has(sum, a, b)) {
        for(auto c : a) {
            cout << c << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
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