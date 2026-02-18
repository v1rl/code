#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector f(n + 1, vector(24, 0));
    for(int i = 1; i <= n; i ++) {
        f[i][0] = a[i];
    }
    for(int j = 1; j < 24; j ++) {
        for(int i = 1; i <= n; i ++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
        }
    }

    for(int i = 1; i <= n; i ++) {
        cout << f[i][23] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}