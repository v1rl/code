#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

// 阻断点在1的旁边
// int cnt = 1;
// char o[] = "00001";

void solve() {
    int n, k;
    cin >> n >> k;
    // n = 5, k = cnt ++;
    vector<int> a(n + 2);
    bool f = false;
    for(int i = 1; i <= n; i ++) {
        char x;
        cin >> x;
        if(x == '1') {
            int l = i - k, r = i + k;

            a[i] += 1;
            a[min(r, n) + 1] -= 1;

            if(r > n) {
                r -= n;
                if(r >= i - 1) {
                    f = true;
                } else {
                    a[1] += 1;
                    a[r + 1] -= 1;
                }
            } 

            a[max(l, 1)] += 1;
            a[i + 1] -= 1;

            if(l < 1) {
                l += n;
                if(l <= i + 1) {
                    f = true;
                } else {
                    a[l] += 1;
                    a[n + 1] -= 1;
                }
            }
        }
    }

    if(f) {
        cout << 0 << '\n';
        return;
    }

    vector<int> b(a.size() * 2);
    int br = 0;
    for(int i = 1; i <= n; i ++) {
        a[i] += a[i - 1];
        if(a[i]) br ++; 
        // cerr << a[i] << ' ';
    }
    // cerr << '\n';
    for(int i = 1; i <= n; i ++) {
        b[i] = b[i + n] = a[i];
    }

    int mx = 0;
    int num = 0;
    for(int i = 1; i <= n * 2; i ++) {
        if(b[i] != 1) {
            mx = max(mx, num);
            num = 0;
        } else {
            num ++;
        }
    }
    mx = max(mx, num);

    int s = min(mx - 1, k - 1);
    s = max(s, 0);
    int ans = n - br + s;
    cout << ans << '\n';

}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}