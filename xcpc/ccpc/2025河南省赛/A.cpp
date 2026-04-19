#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n;
    cin >> n;
    int t = sqrt(n);


    string s = to_string(n);
    int m = 0;
    for(auto c : s) {
        m += c - '0';
    }

    int tt = sqrt(m);

    if(t * t == n && tt * tt == m) {
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
