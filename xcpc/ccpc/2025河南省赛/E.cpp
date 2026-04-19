#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;

struct Trie {
    vector<array<int, 26>> trie;
    vector<int> cnt;
    int idx = 0;

    Trie(int n) {
        trie.assign(n + 1, {});
        cnt.assign(n + 1, 0);
    }

    void insert(string s) {
        int p = 0;
        for(auto c : s) {
            int ch = c - 'a';
            if(!trie[p][ch]) {
                trie[p][ch] = ++idx;
            }
            p = trie[p][ch];
            cnt[p] ++;
        }
    }

    i64 get() {
        i64 res = 0;
        auto dfs = [&](auto &&self, int x) -> void {
            if(x != 0) {
                int a = cnt[x] / 2, b = (cnt[x] + 1) / 2;
                res += 1ll * a * b;
            }
            for(int i = 0; i < 26; i ++) {
                int y = trie[x][i];
                if(y) {
                    self(self, y);
                }
            }
        };
        dfs(dfs, 0);
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    Trie trie(200000);
    for(int i = 0; i < n * 2; i ++) {
        string s;
        cin >> s;
        trie.insert(s);
    }

    cout << trie.get() << '\n';
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
