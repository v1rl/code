#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

const double EPS = 1e-8;
double sgn(double x) {
    if(fabs(x) < EPS) {
        return 0;
    }
    return x < 0 ? -1 : 1;
}

pair<int, vector<double>> gauss(int n, auto &g) {
    for(int x = 1; x <= n; x ++) {
        int sel = x;
        for(int i = 1; i <= n; i ++) {
            if(i < x && sgn(g[i][i]) != 0) {
                continue;
            }
            if(fabs(g[i][x]) > fabs(g[sel][x])) {
                sel = i;
            }
        }

        if(sgn(g[sel][x]) == 0) {
            continue;
        }

        swap(g[x], g[sel]);
        double div = g[x][x];
        for(int j = x; j <= n + 1; j ++) {
            g[x][j] /= div;
        }
        for(int i = 1; i <= n; i ++) {
            if(i != x) {
                double fac = g[i][x];
                for(int j = x; j <= n + 1; j ++) {
                    g[i][j] -= fac * g[x][j];
                }
            }
        }
    }

    int f = 1;
    vector<double> ans(n + 1);
    for(int x = 1; x <= n; x ++) {
        if(sgn(g[x][x]) == 0) {
            if(sgn(g[x][n + 1]) == 0) {
                f = 0;
            } else {
                f = -1;
                break;
            }
        } else {
            ans[x] = g[x][n + 1];
        }
    }

    return {f, ans};
}

void solve() {
    int n;
    cin >> n;
    vector g(n + 1, vector(n + 2, (double)0.0));
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n + 1; j ++) {
            cin >> g[i][j];
        }
    }

    auto [f, ans] = gauss(n, g);

    if(f == 1) {
        for(int i = 1; i <= n; i ++) {
            cout << "x" << i << "=" << ans[i] << '\n';
        }
    } else {
        cout << f << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(8);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}