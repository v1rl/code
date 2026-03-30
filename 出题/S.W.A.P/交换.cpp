#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
*/

const int inf = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    for(int i = 0; i < m; i ++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        l1 --, r1 --, l2 --, r2 --;
        reverse(s.begin() + l1, s.begin() + r1 + 1);
        reverse(s.begin() + l2, s.begin() + r2 + 1);
        if(r1 + 1 < l2) {
            reverse(s.begin() + r1 + 1, s.begin() + l2);
        }
        reverse(s.begin() + l1, s.begin() + r2 + 1);
    }

    cout << s << '\n';
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
