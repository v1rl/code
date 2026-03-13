#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
题目条件符合公平组合游戏,考虑SG函数/PN函数
需要将题目的解空间变成一个有向无环图DAG
如果考虑所有子串,解空间复杂度来到平方级别,显然无法通过
注意到：每次在当前字符串后面加一个字符，维护所有可能性的DAG，这就是后缀自动机的转移图
所以，维护一个后缀自动机，然后用转移图跑博弈论PN函数即可
*/

const int mod = 998244353;

struct SuffixAutomaton {
    static constexpr int N = 26;
    int cnt = 0, lst = 0;
    vector<int> link, len;
    vector<array<int, N>> adj;

    // endpos中点的个数,即子串的出现次数
    vector<i64> occ;
    // 当前子串集首次出现的位置(得到的是末尾字符的位置)
    vector<int> fpos;

    SuffixAutomaton(const string &s) {
        build(s);
    }

    void init(int n) {
        cnt = lst = 0;
        int M = n * 2;

        link.resize(M);
        len.resize(M);
        adj.assign(M, {});
        occ.resize(M);
        fpos.resize(M);

        link[0] = -1, len[0] = 0;
        for(auto &x : adj) {
            x.fill(-1);
        }
    }

    void build(const string &s) {
        int n = s.size();
        init(n);
        for(int i = 0; i < n; i ++) {
            extend(s[i] - 'a', i);
        }
        build_info();
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

    // 是否包含子串 t
    bool contains(const string &t) {
        int x = 0;
        for(auto c : t) {
            int ch = c - 'a';
            if(ch < 0 || ch >= N) {
                return false;
            }
            x = adj[x][ch];
            if(x == -1) {
                return false;
            }
        }
        return true;
    }

    // 不同的子串个数
    i64 ds() {
        i64 res = 0;
        for(int i = 1; i <= cnt; i ++) {
            res += len[i] - len[link[i]];
        }
        return res;
    }

    // 初始化occ,在完成后缀自动机的初始化后调用
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

    // 最长公共子串
    int LCS(const string &t) {
        int p = 0;
        int res = 0;
        int ans = 0;

        for(auto c : t) {
            int ch = c - 'a';
            if(ch < 0 || ch >= N) {
                p = 0, res = 0;
                continue;
            }

            if(adj[p][ch] != -1) {
                p = adj[p][ch];
                res ++;
            } else {
                while(p != -1 && adj[p][ch] == -1) {
                    p = link[p];
                }
                // 如果根节点都没有 c 的出边，说明 c 在原串中从未出现过, 直接跳过
                if(p == -1) {
                    p = 0, res = 0;
                    continue;
                }
                res = len[p] + 1;
                p = adj[p][ch];
            }

            ans = max(ans, res);
        }
        return ans;
    }

    // 查询子串出现次数
    int querNocc(const string &t) {
        int p = 0;
        for(auto c : t) {
            int ch = c - 'a';
            if(adj[p][ch] == -1) {
                return 0;
            }
            p = adj[p][ch];
        }
        return occ[p];
    }

    // 查询子串出现的第一个位置(0-index)
    int queryFocc(const string &t) {
        int p = 0;
        for(auto c : t) {
            int ch = c - 'a';
            if(adj[p][ch] == -1) {
                return 0;
            }
            p = adj[p][ch];
        }
        return fpos[p] - t.size() + 1;
    }
};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    SuffixAutomaton sam(s);

    string t;
    cin >> t;
    cout << sam.queryFocc(t) << '\n';
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