#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 2e9;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int t = (n + 1) / 2;
    for(int i = 1; i <= n; i ++) {
        if(a[i] <= t) {
            a[i] = (t + 1) / 2;
        }
        cout << a[i] << ' ';
    }
    cout << '\n';
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