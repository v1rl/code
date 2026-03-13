#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;

/*
*/

struct SuffixAutomaton {
    static constexpr int N = 27;
    static constexpr int M = 21;

    int cnt = 0, lst = 0;
    vector<int> link, len;
    vector<array<int, N>> adj;

    // endpos中点的个数,即子串的出现次数
    vector<i64> occ;
    // 当前子串集首次出现的位置(得到的是末尾字符的位置)
    vector<int> fpos;

    // dfs序+RMQ相关
    vector<int> preId;
    vector<vector<int>> adjT;
    vector<int> dfn;
    vector<array<int, M>> st;
    vector<int> lg;

    SuffixAutomaton(const string &s) {
        build(s);
    }

    void init(int n) {
        cnt = lst = 0;
        int S = n * 2 + 5;

        link.resize(S);
        len.resize(S);
        adj.assign(S, {});
        occ.resize(S);
        fpos.resize(S);

        preId.resize(n + 1);

        link[0] = -1, len[0] = 0;
        for(auto &x : adj) {
            x.fill(-1);
        }
    }

    void build(const string &s) {
        int n = s.size();
        init(n);
        for(int i = 0; i < n; i ++) {
            int ch = 26;
            if(s[i] != '#') {
                ch = s[i] - 'a';
            }
            extend(ch, i);
            preId[i + 1] = lst;
        }
        build_info();
        build_rmq();
    }

    void extend(int ch, int id) {
        int cur = ++ cnt;
        len[cur] = len[lst] + 1;
        occ[cur] = 1;
        fpos[cur] = id;

        int p = lst;
        lst = cur;

        while(p != -1 && adj[p][ch] == -1) {
            adj[p][ch] = cur;
            p = link[p];
        }

        if(p == -1) {
            link[cur] = 0;
            return;
        }

        int q = adj[p][ch];
        if(len[p] + 1 == len[q]) {
            link[cur] = q;
        } else {
            int cl = ++ cnt;
            len[cl] = len[p] + 1;
            occ[cl] = 0;
            fpos[cl] = fpos[q];

            adj[cl] = adj[q];
            while(p != -1 && adj[p][ch] == q) {
                adj[p][ch] = cl;
                p = link[p];
            }
            
            link[cl] = link[q], link[cur] = link[q] = cl;
        }
    }

    // 初始化occ, 在完成后缀自动机的初始化后记得调用
    void build_info() {
        // 用桶+前缀和,实现按照len从大到小的拓扑排序
        int mxlen = len[lst];
        vector<int> bk(mxlen + 1);
        for(int i = 1; i <= cnt; i ++) {
            bk[len[i]] ++;
        }
        for(int i = 1; i <= mxlen; i ++) {
            bk[i] += bk[i - 1];
        }
        vector<int> rank(cnt + 1);
        for(int i = 1; i <= cnt; i ++) {
            rank[bk[len[i]] --] = i;
        }

        for(int i = cnt; i >= 1; i --) {
            int x = rank[i];
            int p = link[x];
            if(p != -1) {
                occ[p] += occ[x];
            }
        }
    }

    void build_rmq() {
        // 存在空的初始节点0，所以节点是0~cnt
        adjT.assign(cnt + 1, {});
        for(int x = 1; x <= cnt; x ++) {
            // 注意不要写成adj
            adjT[link[x]].emplace_back(x);
        }

        dfn.assign(cnt + 1, 0);
        st.assign(cnt + 2, {});
        int tsp = 0;
        auto dfs = [&](auto &&self, int x, int p) -> void {
            dfn[x] = ++ tsp;
            st[dfn[x]][0] = p;
            for(auto y : adjT[x]) {
                if(y == p) {
                    continue;
                }
                self(self, y, x);
            }
        };

        dfs(dfs, 0, 0);

        auto getMin = [&](int x, int y) {
            return dfn[x] < dfn[y] ? x : y;
        };

        for(int j = 1; j < M; j ++) {
            int len = 1 << j;
            int half = len >> 1;
            // cnt + 1个节点，且dfn从 1 开始
            for(int i = 1; i + len - 1 <= cnt + 1; i ++) {
                st[i][j] = getMin(st[i][j - 1], st[i + half][j - 1]);
            }
        }

        lg.assign(cnt + 1, 0);
        for(int i = 2; i <= cnt; i ++) {
            lg[i] = lg[i >> 1] + 1;
        }
    }

    // 两点LCA的长度，即为两点所代表字符串的最长公共后缀的长度
    int queryLca(int x, int y) {
        if(x == y) return x;
        x = dfn[x], y = dfn[y];
        if(x > y) {
            swap(x, y);
        }
        
        x ++;
        int j = lg[y - x + 1];
        
        auto getMin = [&](int a, int b) {
            return dfn[a] < dfn[b] ? a : b;
        };
        
        return getMin(st[x][j], st[y - (1 << j) + 1][j]);
    }

    int getLcs(int len1, int len2) {
        if (len1 == 0 || len2 == 0) return 0;
        int x = preId[len1];
        int y = preId[len2];
        return len[queryLca(x, y)];
    }
};

void solve() {
    string s, t;
    cin >> s >> t;
    for(auto &c : s) {
        c = tolower(c);
    }
    for(auto &c : t) {
        c = tolower(c);
    }
    int n = s.size(), m = t.size();

    s = t + "#" + s;

    SuffixAutomaton sam(s);

    int S = s.size();

    auto getLcs = [&](int pos, int cur) {
        int len1 = pos + m - cur; 
        int len2 = m - cur;
        return sam.getLcs(len1, len2);
    };

    int ans = 0;

    for(int i = 0; i <= n - m; i ++) {
        int pos = i + m + 1;
        int cur = 0;

        int t = 4;
        while(t --) {
            int len = getLcs(pos, cur);
            cur += len;
            
            if(t > 0) {
                cur ++;
            }
            
            if(cur >= m) {
                ans ++;
                break;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}