#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
概率套皮的背包
*/

const i64 inf = 1e18 + 10;

void solve() {
    int n;
    cin >> n;
    vector<double> p(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> p[i];
    }
    vector<double> f(n + 1);
    f[0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = n; j >= 0; j --) {
            f[j] = f[j] * (1 - p[i]);
            if(j > 0) {
                f[j] += f[j - 1] * p[i];
            }
        }
    }

    double ans = 0;
    for(int i = (n + 1) / 2; i <= n; i ++) {
        ans += f[i];
    }
    cout << fixed << setprecision(15);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}