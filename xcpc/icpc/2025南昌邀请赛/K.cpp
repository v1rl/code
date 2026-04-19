#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    int ans[4] {};
    vector<int> pos(4, -1);
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        int x = a[i];
        for(int j = 0; j < 4; j ++) {
            ans[j] += (x - j + 4) % 4;
            if(x == j) {
                pos[j] = i;
            }
        }
    }
    int mn = 1e9;
    for(int i = 0; i < 4; i ++) {
        if(pos[i] != -1) {
            int add = (4 - (a[pos[i]] + ans[i]) % 4) % 4;
            mn = min(mn, ans[i] + add);
        }
    }

    cout << mn << '\n';
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
