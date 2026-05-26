#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 2e9;

struct Mat {
    int n, m;
    vector<vector<int>> mat;
    Mat(int n_) {
        init(n_, n_);
    }

    Mat(int n_, int m_) {
        init(n_, m_);
    }

    void init(int n_, int m_) {
        n = n_;
        m = m_;
        mat.assign(n, vector<int>(m, inf));
    }
};

Mat operator*(const Mat &A, const Mat &B) {
    Mat c(A.n, B.m);
    for(int i = 0; i < A.n; i ++) {
        for(int k = 0; k < A.m; k ++) {
            if(A.mat[i][k] == inf) {
                continue;
            }
            for(int j = 0; j < B.m; j ++) {
                c.mat[i][j] = min(c.mat[i][j], max(A.mat[i][k], B.mat[k][j]));
            }
        }
    }
    return c;
}

Mat qmi(Mat A, i64 b) {
    Mat res(A.n);
    bool fst = false;

    while(b) {
        if(b & 1) {
            if(!fst) {
                res = A; 
                fst = true;
            } else {
                res = res * A;
            }
        }
        A = A * A;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    Mat A(n);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        A.mat[x][y] = 0;
    }

    int k;
    cin >> k;
    for(int i = 1; i <= k; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        A.mat[x][y] = min(A.mat[x][y], i);
    }

    int q;
    i64 w;
    cin >> q >> w;

    Mat R = qmi(A, w);

    for(int i = 0; i < q; i ++) {
        int x, y;
        cin >> x >> y;
        x --, y --;

        int ans = R.mat[x][y];
        cout << (ans == inf ? -1 : ans) << '\n'; 
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
    return 0;
}
