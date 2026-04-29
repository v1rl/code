#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

void solve() {
    string s;
    cin >> s;
    for(int i = 0, j = s.size() - 1; i < j; ) {
        if(s[i] == s[j]) {
            i ++, j --;
        } else {
            if(s[i] == 'm' && j - 1 > 0 && s[j - 1] == 'n') {
                j -= 2;
                i ++;
            } else if(s[j] == 'm' && i + 1 < s.size() && s[i + 1] == 'n') {
                i += 2;
                j --;
            } else {
                cout << "NO" << '\n';
                return;
            }
            if(i > j + 1) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
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
