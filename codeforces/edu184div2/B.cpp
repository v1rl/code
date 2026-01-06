#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    string s;
    cin >> s;
    if(s.size() == 1) {
        cout << 1 << '\n';
        return;
    }
    int ans = 0;
    int num = 0;
    bool f = false;
    for(int i = 0; i < s.size(); i ++) {
        if(i < s.size() - 1 && (s[i] == '>' && s[i + 1] == '<') || (s[i] == '>' && s[i + 1] == '*' || s[i] == '*' && s[i + 1] == '<') || (s[i] == '*' && s[i + 1] == '*')) {
            cout << -1 << '\n';
            return;
        }
        if(s[i] == '*') {
            f = true;
        }
        if(i != 0 && s[i] != s[i - 1]) {
            ans = max(ans, num);
            num = 0;
        }
        num ++;
    }
    ans = max(ans, num);
    if(f) {
        ans ++;
    }
    cout << ans << '\n';
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
