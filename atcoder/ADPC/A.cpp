#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/
const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> f(n + 1, inf);
    f[1] = 0;
    f[2] = abs(a[2] - a[1]);
    for(int i = 3; i <= n; i ++) {
        f[i] = min(f[i - 2] + abs(a[i - 2] - a[i]), f[i - 1] + abs(a[i - 1] - a[i]));
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