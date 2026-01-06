#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

void solve() {
	i64 n, m;
	cin >> n >> m;
	i64 t = n / m;
	i64 ans = min({m - 1, t + n / t - m, t + 1 + m - n / (t + 1)});
	cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}