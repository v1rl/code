#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 1e9 + 7;

struct Mat {
    vector<vector<int>> mat;
    int n, m;
    Mat(int n_) {
        n = m = n_;
        mat.assign(n, vector<int>(n, 0));
    }
    Mat(int n_, int m_) {
        n = n_;
        m = m_;
        mat.assign(n, vector<int>(m, 0));
    }

    void ident() {
        for(int i = 0; i < n; i ++) {
            mat[i][i] = 1;
        }
    }
};

Mat operator*(const Mat &a, const Mat &b){
    Mat res(a.n, b.m);
    for(int i = 0; i < a.n; i ++) {
        for(int j = 0; j < b.m; j ++) {
            for(int k = 0; k < a.m; k ++) {
                res.mat[i][j] += 1ll * a.mat[i][k] * b.mat[k][j] % mod;
                res.mat[i][j] %= mod;
            }
        }
    }
    return res;
}

Mat qmi(Mat a, i64 b) {
    Mat res(a.n);
    res.ident();
    while(b) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    i64 k;
    cin >> n >> k;
    Mat a(n);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> a.mat[i][j];
        }
    }
    
    Mat ans = qmi(a, k);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << ans.mat[i][j] << " \n"[j == n - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}