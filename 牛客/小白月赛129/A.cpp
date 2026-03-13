#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    string ans;
    bool f = false;
    for(int i = 0; i < s.size() - 1; i ++) {
        if(s[i] == '/' && s[i] == s[i + 1]) {
            ans = s.substr(0, i);
            f = true;
            break;
        }
    }

    if(!f) {
        ans = s;
    }
    if(!ans.empty()) {
        cout << ans << '\n';
    } else {
        cout << "null" << '\n';
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