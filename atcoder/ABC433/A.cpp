#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int d = n - m * k;
    if(d >= 0 && d % (k - 1) == 0) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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