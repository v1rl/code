#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    if(n == 1) {
        cout << a[1] << '\n';
    } else {
        cout << 1ll * mx * (n - 2) + a[n] + a[1] << '\n';
    }

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