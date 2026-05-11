#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    int a[] = {0, 700, 1100, 1500, 2000, 2400, 2800, inf};
    int r = 1000;
    int n;
    cin >> n;
    vector<int> ans(7);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        r += x;
        for(int j = 0; j < 7; j ++) {
            if(r >= a[j] && r < a[j + 1]) {
                ans[j] ++;
            }
        }
    }

    for(int i = 0; i < 7; i ++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
