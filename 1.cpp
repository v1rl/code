#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using poly = vector<i64>;
const int mod = 998244353;
i64 k;

/*
情况x与情况y各自独立为总答案提供贡献，
情况x与情况y提供贡献的方案数已知
问总答案获得贡献的方案数

将两种情况的方案数多项式相乘即可得到答案的方案数多项式

扩展到三(四)种情况为总答案提供贡献亦是同理，三个多项式相乘即可
本题难点在于，第三(四)种情况的多项式受到另外两种情况的约束
*/

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int fact[210], infact[210];
void init(int n) {
    fact[0] = infact[0] = 1;
    for(int i = 1; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
    }
    infact[n] = qmi(fact[n], mod - 2);
    for(int i = n - 1; i >= 1; i --) {
        infact[i] = 1ll * infact[i + 1] * (i + 1) % mod;
    }
}


int C(int a, int b) {
    if(a < b) {
        return 0;
    }
    return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
}

// n方的卷积写法，这里数据较小所以可以这么写
/*
两种情况（在本题中是不同位的两种情况，即a0、b1和a1、b0）共同构成答案（体现在循环里就是i和j）
两种情况的答案方案数各自对应一个多项式
总答案方案数的多项式即为两个多项式的卷积
*/
poly mult(const poly &a, const poly &b) {
    poly c(a.size() + b.size() - 1);
    for(int i = 0; i < a.size(); i ++) {
        for(int j = 0; j < b.size(); j ++) {
            c[i + j] += 1ll * a[i] * b[j] % mod;
            c[i + j] %= mod;
        }
    }
    return c;
}

/*
a、b两边存在的所有数已经可以任意匹配（即完全匹配），则可以直接得到答案多项式
此时选i个的方案数即为a中选i个方案数 * b中选i个方案数 * 二者完全匹配方案数
*/
poly full(int a, int b) {
    poly c(min(a, b) + 1);
    for(int i = 0; i < c.size(); i ++) {
        c[i] = 1ll * C(a, i) * C(b, i) % mod * fact[i] % mod;
    }
    return c;
}

poly work(vector<i64> &a, vector<i64> &b, int bit) {
    if(a.empty() || b.empty()) {
        return poly{1};
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

    vector<poly> C(2);
    C[0] = work(A[0], B[0], bit - 1), C[1] = work(A[1], B[1], bit - 1);

    poly res(min(a.size(), b.size()) + 1);
    for(int i = 0; i < C[0].size(); i ++) {
        for(int j = 0; j < C[1].size(); j ++) {
            i64 base = C[0][i] * C[1][j] % mod;
            // a0、b1和a1、b0这两种情况，需要从a0、b0和a1、b1这前两种情况所剩余下来的那部分中计算得出，然后统一为dif
            i64 a0res = A[0].size() - i, a1res = A[1].size() - j;
            i64 b0res = B[0].size() - i, b1res = B[1].size() - j;
            poly dif = mult(full(a0res, b1res), full(a1res, b0res));
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
    // cerr << 'h';
    while(ans.size() < n + 1) {
        // cerr << 'h';
        ans.emplace_back(0);
    } 
    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << '\n';
    }
}


int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}