#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

vector<int> manacher(string &s) {
    string t = "#";
    for(auto c : s) {
        t += c;
        t += '#';
    }
    int n = t.size();
    vector<int> r(n);
    for(int i = 0, j = 0; i < n; i ++) {
        if(j + r[j] > i) {
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

    vector<int> l(n + 1), r(n + 1);

    for(int i = 0; i < 2 * n + 1; i ++) {
        int len = mch[i];
        if(len > 1) {
            l[(i - len + 2) / 2] += 1;
            l[(i - 1) / 2 + 1] -= 1;
            r[i / 2] += 1;
            r[(i + len - 2) / 2 + 1] -= 1;
        }
    }

    for(int i = 1; i < n; i ++) {
        l[i] += l[i - 1];
        r[i] += r[i - 1];
    }

    for(int i = n - 2; i >= 0; i --) {
        l[i] += l[i + 1];
    }

    i64 ans = 0;
    for(int i = 0; i < n - 1; i ++) {
        ans += 1ll * r[i] * l[i + 1];
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
