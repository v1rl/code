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
    int n = s.size();

    unordered_map<char, int> mp {
        {'l', 1},
        {'o', 2},
        {'s', 3},
        {'e', 4}
    };

    vector<int> res;
    for(int i = 0; i < n; i ++) {
        if(!mp[s[i]]) {
            continue;
        }
        int len = 1;
        while(i + 1 < n && mp[s[i]] < mp[s[i + 1]]) {
            len ++; 
            i ++;
        }
        res.emplace_back(4 - len);
    }

    int ans = 0;
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); i ++) {
        k -= res[i];
        if(k >= 0) {
            ans ++;
        }
    }
    ans += max(0, k / 4);
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
