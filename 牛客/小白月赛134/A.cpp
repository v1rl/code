#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

void solve() {
    int a, b;
    cin >> a >> b;
    if(a & 1 || (b & 1 && a < 2)) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
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
