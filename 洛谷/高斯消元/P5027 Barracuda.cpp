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

pair<int, vector<double>> guass(int n, auto g) {
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
    vector g(n + 2, vector(n + 2, (double)0.0));
    for(int i = 1; i <= n + 1; i ++) {
        int m;
        cin >> m;
        for(int j = 0; j < m; j ++) {
            int x;
            cin >> x;
            g[i][x] ++;
        }
        cin >> g[i][n + 1];
    }

    int ans = 0;
    int cnt = 0;
    for(int i = 1; i <= n + 1; i ++) {
        swap(g[i], g[n + 1]);

        auto [f, res] = guass(n, g);
        if(f == 1) {
            bool ok = true;
            double mx = 0.0;
            int id = 0;

            for(int j = 1; j <= n; j ++) {
                if(sgn(res[j] - mx) > 0) {
                    mx = res[j];
                    id = j;
                }

                if(sgn(res[j]) <= 0) {
                    ok = false;
                }

                if(sgn(res[j] - (int)res[j]) != 0) {
                    ok = false;
                }
            }

            int t = 0;
            for(int j = 1; j <= n; j ++) {
                if(sgn(res[j] - mx) == 0) {
                    t ++;
                }
            }
            if(t > 1) {
                ok = false;
            }

            if(ok) {
                cnt ++;
                ans = id;
            }
        }

        swap(g[i], g[n + 1]);
    }


    if(cnt == 1) {
        cout << ans << '\n';
    } else {
        cout << "illegal" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(3);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}