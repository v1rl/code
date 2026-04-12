#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

void solve() {
    char s[] = {'r', 'e', 'd'};
    string t;
    cin >> t;
    for(auto c : t) {
        bool ok = false;
        for(int i = 0; i < 3; i ++) {
            ok |= (c == s[i]);
        }
        if(!ok) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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
