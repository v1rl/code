#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const int inf = 1e9 + 7;

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

    int i = 1, j = 0;
    while(1) {
        int cnt = 0;
        while(j < m && abs(b[j] - a[i - 1]) <= k) {
            cnt ++;
            j ++;
        }
        while(i < n && abs(a[i] - b[j - 1]) <= k) {
            i ++;
            cnt ++;
        }
        if(!cnt) {
            break;
        }
    }

    if(i == n && j == m) {
        cout << "WIIIIIN?" << '\n';
    } else {
        cout << "LOOOOSE!" << '\n';
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
