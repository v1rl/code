#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    string s;
    cin >> s;
    cout << s.substr(0, s.size() / 2) + s.substr(s.size() / 2 + 1);
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
