#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    k = (k & 1) * n;
    int sum = accumulate(a.begin(), a.end(), 0);
    if((sum & 1) || !(k & 1)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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
