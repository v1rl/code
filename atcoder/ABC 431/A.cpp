#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end(), greater());
    int t = 0;
    for(int i = 0, j = 0; i < n; i ++) {
        if(a[i] <= b[j]) {
            t ++;
            j ++;
        }
        if(j == m) {
            break;
        }
    }
    cout << (t >= k ? "Yes" : "No") << '\n';
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