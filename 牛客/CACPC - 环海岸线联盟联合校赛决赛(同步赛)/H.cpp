#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;

    for(auto c : s) {
        int ch = 10 - (c - '0');
        if(ch == 10) {
            ch = 0;
        }

        if(ch == 7) {
            cout << 'L';
        } else {
            cout << ch;
        }
    }
    cout << '\n';
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
