#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    i64 res = 0;
    int cnt = 0;
    int suf0 = 0;
    for(auto c : s) {
        if(c == '1') {
            cnt ++;
        } else {
            res += cnt;
            suf0 ++;
        }
    }

    i64 ans = res;
    int pre1 = 0;
    for(auto c : s) {
        if(c == '1') {
            pre1 ++;
        } else if(c == '0') {
            suf0 --;
        } else {
            suf0 --;
            res -= pre1;
            res += suf0;
            pre1 ++;

            ans = max(ans, res);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}