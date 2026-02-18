#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/
const int inf = 1e9 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> f(n + 1, inf);
    f[1] = 0;
    for(int i = 2; i <= n; i ++) {
        for(int j = 1; j <= min(k, i - 1); j ++) {
            f[i] = min(f[i], f[i - j] + abs(a[i] - a[i - j]));
        }
    }

    cout << f[n] << '\n';
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