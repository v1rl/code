#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        a[i] = {x, i};
    }

    sort(a.begin(), a.end());
    for(int i = 0; i < 3; i ++) {
        cout << a[i][1] + 1 << ' ';
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
