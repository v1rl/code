#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const i64 inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        ans += x / m;
        a[i] = x % m;
    }
    sort(a.begin(), a.end(), greater());
    int k;
    cin >> k;
    for(auto c : a) {
        if(k >= m - c) {
            k -= m - c;
            ans ++;
        }
    }
    ans += k / m;
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
