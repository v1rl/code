#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 1e9;

void solve() {
    i64 n;
    cin >> n;

    vector<i64> ans;
    for(i64 i = 10; i + 1 <= n; i *= 10) {
        if(n % (i + 1) == 0) {
            ans.emplace_back(n / (i + 1));
        }
    }

    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for(auto c : ans) {
        cout << c << " \n"[c == ans.back()];
    }
}


signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}