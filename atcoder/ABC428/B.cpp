#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const i64 inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    unordered_map<string, int> mp;
    int mx = 0;
    for(int i = 0; i < n - m + 1; i ++) {
        string t = s.substr(i, m);
        mp[t] ++;
        mx = max(mx, mp[t]);
    }
    vector<string> ans;
    for(auto [c, d] : mp) {
        if(d == mx) {
            ans.emplace_back(c);
        }
    }
    sort(ans.begin(), ans.end());
    cout << mx << '\n';
    for(auto c : ans) {
        cout << c << '\n';
    }
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
