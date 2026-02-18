#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/
const int inf = 1e9 + 10;

void solve() {
    string s;
    cin >> s;
    string t = s;
    reverse(t.begin(), t.end());
    if(s == t) {
        cout << "equal" << '\n';
    } else {
        cout << (s > t ? "left" : "right") << '\n';
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