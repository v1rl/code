#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

// https://acm.hdu.edu.cn/showproblem.php?pid=5833

const int mod = 1e9 + 7;

vector<int> minp, primes;
void sieve(int n) {
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++) {
        if(!minp[i]) {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes) {
            if(p * i > n) {
                break;
            }
            minp[p * i] = p;
            if(minp[i] == p) {
                break;
            }
        }
    }
}

template<class T>
struct LinearBasis {
    // 注意根据数据最高位修改
    const int N = 302;
    vector<T> b, g;

    int sz = 0;
    bool zero = false;
    bool dirty = true;
    LinearBasis() : b(N + 1) {};

    bool insert(T x) {
        dirty = true;
        for(int i = N; i >= 0; i --) {
            if(x[i]) {
                if(b[i].any()) {
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

    int rank() {
        return sz;
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

int tt = 0;

void solve() {
    int n;
    cin >> n;
    LinearBasis<bitset<303>> lb;

    for(int i = 1; i <= n; i ++) {
        bitset<303> bit;
        i64 x;
        cin >> x;
        for(int i = 0; i < 303; i ++) {
            int p = primes[i];
            if(x % p == 0) {
                int cnt = 0;
                while(x % p == 0) {
                    cnt ++;
                    x /= p;
                }
                bit[i] = cnt & 1;
            }
        }
        lb.insert(bit);
    }

    cout << "Case #" << ++ tt << ":\n";
    cout << qmi(2, n - lb.rank()) - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve(2000);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}