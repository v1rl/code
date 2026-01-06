#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
比较容易的猜法是看距离的奇偶与胜负的关系，但根据样例仔细想想，显然不对
注意到博弈论的一个Trick：如果我能明确知道最终获胜条件，那么终点时的赢家就已知了，根据这样的已知条件反推得到答案
于是，我们维护一个dp[i][j]表示当前走了i步，最终站在点j上，属性为Alice是否胜利
对于初始化，我们可以由输入的字符串直接得到
对于转移，从终点反推时Bob先走，Alice后走，所以我们先按照Bob执行转移，更新dp数组后再按照Alice执行转移
对于Bob执行转移，只要相邻有一个false则当前为false，对于Alice执行转移，只要响铃有一个为true则为true
另外，由于dp[i]总是由dp[i + 1]转移得到，我们可以少一个维度

另外，注意到本题特殊的输入范围K，不难做出复杂度为K * M的猜测
*/

const int inf = 1e9;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
    }

    vector<int> f(n + 1);
    s = "#" + s;
    for(int i = 1; i <= n; i ++) {
        if(s[i] == 'A') {
            f[i] = true;
        }
    }

    // 对于任意满足即可的问题，将全体初始化为不满足值，遇到满足条件时做修改
    vector<int> ndp(n + 1);
    for(int i = 0; i < k; i ++) {
        ndp.assign(n + 1, true);
        for(int x = 1; x <= n; x ++) {
            for(auto y : adj[x]) {
                if(!f[y]) {
                    ndp[x] = false;
                    break;
                }
            }
        }
        f = move(ndp);            
        
        ndp.assign(n + 1, false);
        for(int x = 1; x <= n; x ++) {
            for(auto y : adj[x]) {
                if(f[y]) {
                    ndp[x] = true;
                    break;
                }
            }
        }
        f = move(ndp);            
    }

    cout << (f[1] ? "Alice" : "Bob") << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
