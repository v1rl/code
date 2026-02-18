#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> s(m + 1);
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        s[x][0] ++;
        s[x][1] += y;

    }

    cout << fixed << setprecision(6);
    for(int i = 1; i <= m; i ++) {
        cout << 1.0 * s[i][1] / s[i][0] << '\n';
    }
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
