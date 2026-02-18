#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

/*
*/

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cout << "/\\"[(i + j) & 1];
        }
        cout << '\n';
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
