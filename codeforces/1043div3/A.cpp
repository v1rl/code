#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 1e9;

void solve() {
    int n, m;
    string s1, s2, op;
    cin >> n >> s1 >> m >> s2 >> op;
    for(auto c : op) {
        if(c == 'D') {
            s1 += s2[0];
        } else {
            s1.insert(s1.begin(), s2[0]);
        }
        s2.erase(s2.begin(), s2.begin() + 1);
    }

    cout << s1 << '\n';
}


signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}