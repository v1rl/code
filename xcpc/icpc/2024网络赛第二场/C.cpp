#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> ne(n);
    vector<int> s(n), b(n);
    i64 ans = 0, pre = 0;
    vector<vector<int>> fails(n);
    for(int i = 0, j = 0; i < n; i ++) {
        int a;
        cin >> s[i] >> a >> b[i];
        s[i] = (s[i] + ans) % n;
        pre += b[i];
        if(i > 0) {
            while(j && s[i] != s[j]) {
                fails[i].emplace_back(j);
                j = ne[j - 1];
            }

            if(s[i] == s[j]) {
                for(auto x : fails[j]) {
                    fails[i].emplace_back(x);
                }
                j ++;
            } else {
                fails[i].emplace_back(0);
            }
            ne[i] = j;
        }

        for(auto x : fails[i]) {
            pre -= b[i - x];
        }

        ans += a * pre;
        cout << ans << '\n';
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
