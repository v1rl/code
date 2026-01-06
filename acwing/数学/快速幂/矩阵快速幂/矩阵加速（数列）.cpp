#include<bits/stdc++.h>
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
    Mat c(a.n, b.m);
    for(int i = 0; i < a.n; i ++) {
        for(int j = 0; j < b.m; j ++) {
            for(int k = 0; k < a.m; k ++) {
                c.mat[i][j] += 1ll * a.mat[i][k] * b.mat[k][j] % mod;
                c.mat[i][j] %= mod;
            }
        }
    }
    return c;
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
    cin >> n;
    if(n <= 3) {
        cout << 1 << '\n';
    } else {
        Mat a(3);
        a.mat = {
            {0, 0, 1},
            {1, 0, 0},
            {0, 1, 1}
        };
        Mat base(1, 3);
        base.mat = {{1, 1, 1}};
        Mat ans = base * qmi(a, n - 3);
        cout << ans.mat[0][2] << '\n';
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