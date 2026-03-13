#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;

/*
*/

const i64 inf = 1e18 + 10;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int sum = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        sum ^= a[i];
    }

    vector<int> pre(n + 1), suf(n + 2);
    vector<int> num(n + 2);
    for(int i = 1; i <= n; i ++) {
        pre[i] = pre[i - 1] ^ a[i];
    }
    for(int i = n; i >= 1; i --) {
        suf[i] = suf[i + 1] ^ a[i];
        num[i] = num[i + 1] + (suf[i] == sum);
    }

    i64 ans = 0;
    for(int i = 1; i <= n - 2; i ++) {
        if(pre[i] == sum) {
            ans += num[i + 2];
        }
    }

    cout << ans << '\n';
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
