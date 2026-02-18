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
    vector<i64> pre(n + 1), suf(n + 2);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector b = a;

    for(int i = 2; i <= n; i ++) {
        int t = min(a[i], a[i - 1]);
        pre[i] = pre[i - 1] + t;
        a[i] -= t;
    }

    a = b;

    for(int i = n - 1; i >= 1; i --) {
        int t = min(a[i], a[i + 1]);
        suf[i] = suf[i + 1] + t;
        a[i] -= t;
    }

    i64 ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans = max(ans, pre[i - 1] + suf[i + 1] + b[i]);
    }
    cout << ans << '\n';
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
