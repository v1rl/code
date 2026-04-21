#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

vector<int> manacher(string s) {
    string t = "#";
    for(auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for(int i = 0, j = 0; i < n; i ++) {
        if(2 * j - i > 0 && j + r[j] > i) {
            r[i] = min(r[2 * j - i], j + r[j] - i);
        }
        while(i - r[i] >= 0 && i + r[i] < n && t[i - r[i]] == t[i + r[i]]) {
            r[i] ++;
        }
        if(i + r[i] > j + r[j]) {
            j = i;
        }
    }

    return r;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    auto mch = manacher(s);
    vector<int> l(n), r(n);
    for(int i = 0; i < mch.size(); i ++) {
        int cl = (i - mch[i] + 2) / 2;
        int cr = (i + mch[i] - 2) / 2;
        r[cr] = max(r[cr], cr - cl + 1);
        l[cl] = max(l[cl], cr - cl + 1);
    }

    for(int i = n - 2; i >= 0; i --) {
        r[i] = max(r[i], r[i + 1] - 2);
    }
    for(int i = 1; i < n; i ++) {
        l[i] = max(l[i], l[i - 1] - 2);
    }

    int ans = 0;
    for(int i = 0; i < n - 1; i ++) {
        ans = max(ans, r[i] + l[i + 1]);
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
