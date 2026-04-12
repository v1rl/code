#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, _;
    cin >> n >> _;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int k;
    cin >> k;

    int tar = a[k - 1];

    int l = 0, r = n - 1;
    int ans = -1;
    while(1) {
        while(l < n && a[l] == tar) {
            l ++;
        }
        while(r >= 0 && a[r] == tar) {
            r --;
        }
        ans ++;
        tar ^= 1;
        if(l > k - 1 || r < k - 1) {
            break;
        }
    }

    if(l < k - 1) {
        int cnt = 0;
        for(int i = k - 2; i >= l; i --) {
            if(a[i] == tar) {
                cnt ++;
            } else {
                if(cnt) {
                    ans += 2;
                }
                cnt = 0;
            }
        }
        if(cnt) {
            ans += 2;
        }
    } else if(r > k - 1) {
        int cnt = 0;
        for(int i = k; i <= r; i ++) {
            if(a[i] == tar) {
                cnt ++;
            } else {
                if(cnt) {
                    ans += 2;
                }
                cnt = 0;
            }
        }
        if(cnt) {
            ans += 2;
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


