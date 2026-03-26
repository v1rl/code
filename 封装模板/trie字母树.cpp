#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;

struct Trie {
    int n;
    int idx = 0;
    vector<array<int, 26>> trie;

    Trie(int n_) : n(n_), trie(n + 1) {};

    void insert(string s) {
        int p = 0;
        for(auto c : s) {
            int ch = c - 'a';
            if(!trie[p][ch]) trie[p][ch] = ++ idx;
            p = trie[p][ch];
        }
    }

    int find(string s) {
        int p = 0;
        int cnt = 0;
        for(auto c : s) {
            int ch = c - 'a';
            if(!trie[p][ch]) return cnt;
            p = trie[p][ch];
            cnt ++;
        }
        return cnt;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Trie trie(1e6);
    int ans = 0;
    int mxlen = 0;
    vector<string> s(n);
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    while(q --) {
        int l, r;
        cin >> l >> r;
        for(int i = l - 1; i < r; i ++) {
            int len = s[i].size();
            mxlen = max(mxlen, len);
            int pmax = trie.find(s[i]);
            ans += (len - pmax) * 2;
            trie.insert(s[i]);
        }
        cout << ans - mxlen << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}