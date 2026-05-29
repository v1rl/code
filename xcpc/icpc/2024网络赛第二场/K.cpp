#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;
i64 k;

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

vector<int> fact, infact;
void init(int n) {
    fact.resize(n + 1);
    infact.resize(n + 1);

    fact[0] = infact[0] = fact[1] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = 1ll * infact[i - 1] * infact[i] % mod;
    }
}

int C(int a, int b) {
    if(a < b) {
        return 0;
    }
    return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
}

vector<i64> mult(const vector<i64> &a, const vector<i64> &b) {
    vector<i64> c(a.size() + b.size() - 1);
    for(int i = 0; i < a.size(); i ++) {
        for(int j = 0; j < b.size(); j ++) {
            c[i + j] += 1ll * a[i] * b[j] % mod;
            c[i + j] %= mod;
        }
    }
    return c;
}

vector<i64> full(int a, int b) {
    vector<i64> c(min(a, b) + 1);
    for(int i = 0; i < c.size(); i ++) {
        c[i] = 1ll * C(a, i) * C(b, i) % mod * fact[i] % mod;
    }
    return c;
}

vector<i64> work(vector<i64> &a, vector<i64> &b, int bit) {
    if(a.empty() || b.empty()) {
        return vector<i64>{1};
    }
    if(bit == -1) {
        return full(a.size(), b.size());
    }

    vector<vector<i64>> A(2), B(2);
    for(auto x : a) {
        A[x >> bit & 1].emplace_back(x);
    }
    for(auto x : b) {
        B[x >> bit & 1].emplace_back(x);
    }
    if(k >> bit & 1) {
        return mult(work(A[0], B[1], bit - 1), work(A[1], B[0], bit - 1));
    }

    vector<vector<i64>> C(2);
    C[0] = work(A[0], B[0], bit - 1), C[1] = work(A[1], B[1], bit - 1);

    vector<i64> res(min(a.size(), b.size()) + 1);
    for(int i = 0; i < C[0].size(); i ++) {
        for(int j = 0; j < C[1].size(); j ++) {
            i64 base = C[0][i] * C[1][j] % mod;
            i64 a0res = A[0].size() - i, a1res = A[1].size() - j;
            i64 b0res = B[0].size() - i, b1res = B[1].size() - j;
            vector<i64> dif = mult(full(a0res, b1res), full(a1res, b0res));
            for(int k = 0; k < dif.size(); k ++) {
                res[i + j + k] += base * dif[k] % mod;
                res[i + j + k] %= mod;
            }
        }
    }

    return res;
};


void solve() {
    int n;
    cin >> n >> k;
    vector<i64> a(n), b(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i ++) {
        cin >> b[i];
    }
    init(200);
    vector ans = work(a, b, 60);
    while(ans.size() < n + 1) {
        ans.emplace_back(0);
    } 
    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}