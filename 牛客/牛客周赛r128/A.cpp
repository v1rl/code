#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 2e9;

/*
*/

void solve() {
    string s;
    cin >> s;
    if(s[1] == s[2]) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
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