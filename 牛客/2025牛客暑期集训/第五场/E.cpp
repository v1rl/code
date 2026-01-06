#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> c1(30), c0(30);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        int x = a[i];
        for(int j = 0; j < 30; j ++) {
            if(x >> j & 1) {
                c1[j] ++;
            } else {
                c0[j] ++;
            }
        }
    }

    for(int i = 0; i < 30; i ++) {
        int x = c0[i] * c1[i] * (1 << i);
        if(x) {
            cout << i << ' ' << c0[i] << ' ' << c1[i]  << ' ' << x << '\n';
        }
    }


    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            int res = a[i] ^ a[j];
            int x = res;
            int t = 0;
            int cnt = 0;
            while(x) {
                if(x % 2 == 1) {
                    t ++;
                    if(t % 2 == 0) {
                        res -= (1 << cnt);
                    }
                }
                x /= 2;
                cnt ++;
            }
            ans += res;
        }
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}