#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
注意对小集合是从大到小遍历
*/

void solve() {
    int n, k;
    i64 x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    i64 res = 0;
    int ans = 0;
    for(int i = k - 1; i >= 0; i --) {
        res += a[i];
        if(res >= x) {
            ans = k - i;
            break;
        }
    }
    if(ans == 0) {
        cout << -1 << '\n';
        return;
    }
    ans += n - k;
    cout << ans << '\n';
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