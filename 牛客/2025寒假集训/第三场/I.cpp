#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/
template<class T>
struct LinearBasis {
    static const int M = sizeof(T) * 8 - 1;
    vector<T> bit;
    int cnt = 0;

    LinearBasis() {
        init();
    }

    void init() {
        bit.assign(M + 1, 0);
        cnt = 0;
    }

    bool insert(T x) {
        for(int i = M; i >= 0; i --) {
            if(!(x >> i & 1)) {
                continue;
            }
            if(!bit[i]) {
                bit[i] = x;
                return true;
            }
            x ^= bit[i];
        }
        cnt ++;
        return false;
    }

    bool has(T x) const {
        if(x == 0) {
            return cnt > 0;
        }
        for(int i = M; i >= 0; i --) {
            if(x >> i & 1) {
                if(!bit[i]) {
                    return false;
                }
                x ^= bit[i];
            }
        }
        return x == 0;
    }

    T queryMax() const {
        T res = 0;
        for(int i = M; i >= 0; i --) {
            res = max(res, res ^ bit[i]);
        }
        return res;
    }

    T queryMin() const {
        for(int i = 0; i <= M; i ++) {
            if(bit[i]) {
                return bit[i];
            }
        }
        return 0;
    }

    bool get(T x, unordered_map<T, int> &mp) const {
        if(x == 0) {
            return true;
        }
        for(int i = M; i >= 0; i --) {
            if(x >> i & 1) {
                if(!bit[i]) {
                    return false;
                }
                x ^= bit[i];
                mp[bit[i]] ++;
            }
        }
        return x == 0;
    }
};

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum ^= a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
        c[i] = a[i] ^ b[i];
    }

    LinearBasis<int> lb;
    for(int i = 0; i < n; i ++) {
        lb.insert(c[i]);
    }

    unordered_map<int, int> mp;
    if(!lb.get(sum, mp)) {
        cout << -1 << '\n';
    } else {
        for(int i = 0; i < n; i ++) {
            if(mp[c[i]]) {
                mp[c[i]] --;
                cout << b[i] << ' ';
            } else {
                cout << a[i] << ' ';
            }
        }
        cout << '\n';
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