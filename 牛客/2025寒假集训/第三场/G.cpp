#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*

*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());

    i64 sa = accumulate(a.begin(), a.end(), 0ll);
    i64 sb = accumulate(b.begin(), b.end(), 0ll);

    if(sa == sb) {
        cout << 1 << '\n';
        return;
    }
    
    if(sa < sb) {
        swap(sa, sb);
        swap(a, b);
    }

    int ans = 0;
    for(auto x : a) {
        if(sa > sb) {
            ans ++;
            sa -= x;
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