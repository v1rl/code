#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int k = i;
        for(int j = i; j < n; j ++) {
            int tar = a[j] * 2 - a[i];
            while(k < n && a[k] <= tar) {
                k ++;
            }
            if(a[k - 1] == tar) {
                int pos = k - 1;
                int lo = j - i, hi = pos - j;
                if(lo < hi) {
                    ans = max(ans, lo * 2 + 2);
                } else {
                    ans = max(ans, hi * 2 + 1);
                }
            }
        }
    }
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
