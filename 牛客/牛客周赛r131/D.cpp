#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> f(n + 2, 0);
    f[0] = 0;
    for(int i = 1; i <= n; i ++) {
        f[a[i]] = max({1, f[a[i]], f[a[i] - 1] + 1, f[a[i] + 1] + 1});
    }

    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        mx = max(mx, f[i]);
    }

    cout << mx << '\n';

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
