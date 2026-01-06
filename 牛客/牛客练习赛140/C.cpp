#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

// 不重，连续
// 最大为 n
// 若不连续，只能有一个数不存在，最大数执行不存在和本身两次

void solve() {
	int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    vector<int> st(n + 1);
    int mx = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    for(int i = 1; i <= n; i ++) {
        if(a[i][0] > n || (a[i][0] != 0 && st[a[i][0]])) {
            cout << -1 << '\n';
            return;
        }
        mx = max(a[i][0], mx);
        st[a[i][0]] = true;
    }

    sort(a.begin() + 1, a.end());

    if(!st[0]) {
        cout << n << '\n';
        for(int i = 1; i <= n; i ++) {
            cout << a[i][1] << ' ';
        }
    } else {
        bool f = true;
        for(int i = 1; i <= mx; i ++) {
            if(!st[i]) {
                if(f) {
                    f = false;
                } else {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
        cout << a[n][0] << '\n';
        // if(!f) cout << a[n][1] << ' ';
        for(int i = 1; i <= n; i ++) {
            if(a[i][0] == 0) continue;
            if(a[i][0] - a[i - 1][0] > 1) {
                cout << a[n][1] << ' ';
            }
            cout << a[i][1] << ' ';
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}