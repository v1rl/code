#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> bk(1010);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        bk[a[i]] ++;
    }

    for(int i = 1; i <= n; i ++) {
        bk[i] += bk[i - 1];
    }

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if((bk[a[i]] - 1) * 5 >= (n - 1) * 4) {
            ans += a[i];
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
