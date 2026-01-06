#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> s1, s2;
    int cur = 0;
    s1.reserve(n), s2.reserve(n);
    for(int i = 0; i < n; i ++) {
        s1.emplace_back(cur);
        s2.emplace_back(cur ^ 1);
        cur ^= 1;
    }

    int cnt = 0;
    int ans = inf;
    for(int i = 0; i < n - 1; i ++) {
        if(s1[i] != s[i] - '0') {
            s1[i] ^= 1;
            s1[i + 1] ^= 1;
            cnt ++;
        }
    }
    if(s1[n - 1] == s[n - 1] - '0') {
        ans = cnt;
    }
    cnt = 0;
    for(int i = 0; i < n - 1; i ++) {
        if(s2[i] != s[i] - '0') {
            s2[i] ^= 1;
            s2[i + 1] ^= 1;
            cnt ++;
        }
    }
    if(s2[n - 1] == s[n - 1] - '0') {
        ans = min(ans, cnt);
    }

    if(ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}