#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<array<int, 2>>> a(6);
    for(int i = 0; i < n; i ++) {
        char c;
        int x;
        cin >> c >> x;
        a[c - 'A'].push_back({x, i + 1});
    }

    for(int i = 0; i < 6; i ++) {
        sort(a[i].begin(), a[i].end(), greater());
    }

    int sum = 0;
    vector<int> ans;
    for(int i = 0; i < 6; i ++) {
        if(a[i].empty() || a[i][0][0] < 60) {
            cout << -1 << '\n';
            return;
        }
        sum += a[i][0][0];
        ans.emplace_back(a[i][0][1]);
    }

    if(sum < 420) {
        cout << -1 << '\n';
    }

    for(auto c : ans) {
        cout << c << ' ';
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
