#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
无思路->转移的可行性具有单调性->二分->双指针
*/

const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<i64> pre(n + 1);
    vector<int> f(n + 1);
    pre[0] = f[0] = 1;

    int sum = 0;
    for(int l = 1, r = 1; r <= n; r ++) {
        while(sum & a[r]) {
            sum -= a[l];
            l ++;
        }
        sum |= a[r];

        f[r] = pre[r - 1];
        if(l - 2 >= 0) {
            f[r] -= pre[l - 2];
        }
        f[r] = (f[r] % mod + mod) % mod;

        pre[r] = (pre[r - 1] + f[r]) % mod;
    } 

    cout << f[n] << '\n';
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