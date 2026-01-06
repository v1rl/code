#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mx = 0;
    for(int i = 0; i < n; i += 2) {
        mx = max(mx, abs(a[i] - a[i + 1]));
    }
    cout << mx << '\n';
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