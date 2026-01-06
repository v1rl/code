#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

// 连续的1和0是没有意义的

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int lst = -1;
    int res = 0;
    int num = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] == -1) {
            num ++;
            continue;
        }
        if(a[i] != lst) {
            lst = a[i];
            if(a[i] == 1) res ++;
        }
    }

    int ans = qmi(2, num) * num % mod;  
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