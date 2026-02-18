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
    a[0] = k;
    int mx = -inf;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max(mx, a[i] + a[i - 1]);
    }
    mx = max(mx, a[n] + k);
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