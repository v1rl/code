#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i ++) {
        cin >> b[i];
    }

    int j = 0;
    for(int i = 0; i < n; i ++) {
        if(j < m && a[i] >= b[j]) {
            j ++;
        }
    }

    if(j == m) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
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
