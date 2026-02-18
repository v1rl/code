#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

void solve() {
    int n;
    cin >> n;
    bool ok = false;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        ok |= (x == 67);
    }

    cout << (ok ? "YES" : "NO") << '\n';

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
