#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<i64> sum(2);
    vector<int> cnt(2);
    for(int i = 1; i <= n; i ++) {
        char x;
        cin >> x;
        sum[x - '0'] += a[i];
        cnt[x - '0'] ++;
    }

    i64 s = sum[0] + sum[1];
    if(s * cnt[0] % n != 0) {
        cout << -1 << '\n';
    } else {
        cout << abs(s * cnt[0] / n - sum[0]) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}