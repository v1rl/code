#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const int mod = 998244353;

// 最高位同时为1

void solve() {
    vector<int> bit(65);
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    vector<int> mx(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        int t = a[i];
        int p = 0;
        while(t) {
            bit[p] += t % 2;
            t /= 2;
            p ++;
        }
        mx[i] = p - 1;
    }

    for(int i = 1; i <= n; i ++) {
        if(bit[mx[i]] > 1) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';


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