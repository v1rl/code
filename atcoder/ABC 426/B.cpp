#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const int inf = 1e9;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s[0] == s[1]) {
        cout << s.back() << '\n';
    } else {
        cout << s[0] << '\n';
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