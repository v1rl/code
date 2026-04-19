#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    i64 n;
    cin >> n;
    vector<i64> ans;
    while((n & (n - 1)) != 0 || __builtin_ctzll(n) % 2 == 1) {
        ans.emplace_back(n & -n);
        n += n & -n;
    } 
    cout << ans.size() << '\n';
    for(auto c : ans) {
        cout << c << ' ';
    }
    cout << '\n';
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
