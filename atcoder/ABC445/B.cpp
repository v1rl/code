#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    int m = 0;
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
        m = max(m, (int)s[i].size());
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < (m - s[i].size()) / 2; j ++) {
            cout << '.';
        }
        cout << s[i];
        for(int j = 0; j < (m - s[i].size()) / 2; j ++) {
            cout << '.';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed << setprecision(15);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}