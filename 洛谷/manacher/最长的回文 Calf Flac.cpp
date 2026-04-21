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
    char c;
    while(cin.get(c)) {
        if(c == '[') {
            break;
        }
        s += c;
    } 

    vector<int> id;
    string ns;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] >= 'A' && s[i] <= 'Z' || (s[i] >= 'a' && s[i] <= 'z')) {
            ns += tolower(s[i]);
            id.emplace_back(i);
        }
    }

    auto mch = manacher(ns);
    int l = -1, r = -1, len = -1;
    for(int i = 0; i < mch.size(); i ++) {
        int cl = (i - mch[i] + 2) / 2;
        int cr = (i + mch[i] - 2) / 2;
        if(cr - cl + 1 > len) {
            len = cr - cl + 1;
            l = cl, r = cr;
        }
    }

    l = id[l], r = id[r];
    cout << len << '\n';
    cout << s.substr(l, r - l + 1);
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
