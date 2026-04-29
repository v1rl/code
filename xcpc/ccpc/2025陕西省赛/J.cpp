#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    // lose
    vector<string> a = {"l", "lo", "ls", "le", "los", "loe", "lse", "lose"};
    vector<string> b = {"o", "os", "oe", "ose"};
    vector<string> c = {"s", "se"};

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(c.begin(), c.end());

    vector<int> res;
    int m = s.size();
    for(int i = 0; i < m; i ++) {
        int cur = 0;
        if(s[i] == 'l') {
            for(auto t : a) {
                int len = t.size();
                if(s.substr(i, len) == t) {
                    cur = len;
                    break;
                }
            }
        } else if(s[i] == 'o') {
            for(auto t : b) {
                int len = t.size();
                if(s.substr(i, len) == t) {
                    cur = len;
                    break;
                }
            }
        } else if(s[i] == 's') {
            for(auto t : c) {
                int len = t.size();
                if(s.substr(i, len) == t) {
                    cur = len;
                    break;
                }
            }
        } else if(s[i] == 'e') {
            cur = 1;
        }

        if(cur) {
            i += cur - 1;
            res.emplace_back(4 - cur);
        }
    }

    int ans = 0;
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i ++) {
        k -= res[i];
        if(k >= 0) {
            ans ++;
        }
    }
    if(k > 0) {
        ans += k / 4;
    }
    cout << ans << '\n';
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
