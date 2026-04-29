#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt[2] {};
    vector<int> vec[2];
    for(int i = 0; i < s.size(); i ++) {
        int ch = s[i] - '0';
        cnt[ch] ++;
        vec[ch].emplace_back(i + 2);
    }

    if(cnt[0] == 0) {
        cout << -1 << '\n';
        return;
    }

    if((cnt[0] == 1) && s[s.size() - 1] != '0') {
        cout << -1 << '\n';
        return;
    }

    vector<array<int, 2>> ans;

    int lst = 1;
    int p0 = 0, p1 = 0;
    while(cnt[1] --) {
        ans.push_back({lst, vec[1][p1]});
        lst = vec[1][p1];
        p1 ++;
    }
    ans.push_back({lst, n});

    lst = 1;
    while(cnt[0] --) {
        ans.push_back({lst, vec[0][p0]});
        lst = vec[0][p0];
        p0 ++;
    }
    if(p0 > 1) {
        ans.push_back({lst, 1});
    }

    cout << ans.size() << '\n';
    for(auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
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
