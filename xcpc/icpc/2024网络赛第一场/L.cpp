#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
显然，根据题意，我们对按钮序列有一定约束：即要么是排列，要么只有一对数是相等的
题意要求我们判断能否将空位从a变到b
我们不难将思路引导向————在什么情况下，空位会由什么点变到什么点
从而很顺利的转换为对空位可能的转移进行建边，然后便可以通过可达性判断空位a能否到b

现在，我们想想该怎么建边
如果是排列，两个排列(下标排列和值排列)将形成若干个环，所有这些操作可以视作双向边
对于这样的双向边，我下标排列与们可以用并查集只保留会改变连通性的边，控制边的数量最多在n条
如果只有一对数相等，假设相等数所对应的两个下标分别为x1和x2，不存在的数为y，则连边 x1->y 和 x2->y
我们将边权设置为按钮的编号，对于每次询问，我们只需要判断最小瓶颈和c的大小关系即可
于是，我们将问题转换为了建边后求任意两点的最小瓶颈路
MST+DFS+LCA的方法是时间复杂度的最优解，但码量较大
我们考虑另一个做法————跑n次桶优化dijk，其复杂度为O(n*(n + l))，在这里也是能通过的

Trick：桶优化dijk / MST+DFS+LCA跑最小瓶颈路
Trick：两个排列(下标排列和值排列)的连接将形成若干个环，因而在判断连通性上我们可以将边视作双向边，
从而用并查集避免一些需要用SCC的操作

预处理并查集 + 处理读入 + 连边 + 跑dijk + 处理询问

另一种比较麻烦的做法是，离线处理询问，边处理边建边，此时只需要判断可达性即可
。。。做做可达性统计试试看先
*/

const int N = 2010;
int p[N];

int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void solve() {
	int n, m, q;
    cin >> n >> m >> q;
    // 需要注意，时刻注意数组变量名不要重复了
    vector<int> to(n + 1, 0);
    vector<vector<PII>> adj(n + 1);

    for(int i = 1; i <= n; i ++) {
        p[i] = i;
    }

    for(int i = 1; i <= m; i ++) {
        string s;
        cin >> s;
        vector<int> st(n + 1);
        int cnt = 0;
        int val = 0;
        for(int j = 0; j < s.size(); j += 2) {
            char x = s[j], y = s[j + 1];
            int t = (x - 48) * 50;
            t += (y - 48) % 50;
            if(!st[t]) {
                cnt ++;
            }
            st[t] ++;
            if(st[t] > 1) {
                val = t;
            }
            to[j / 2 + 1] = t;
        }

        if(cnt == n) {
            // 需要注意，别用循环中后面会修改的变量当for循环的循环变量
            for(int j = 1; j <= n; j ++) {
                int x = j;
                int y = to[x];
                x = find(x), y = find(y);
                if(x != y) {
                    adj[x].push_back({y, i});
                    adj[y].push_back({x, i});
                    p[y] = x;
                }
            }
        } else if(cnt == n - 1) {
            // 需要注意，非全局变量要手动赋0
            int x1 = 0, x2 = 0;
            int y = 0;
            for(int i = 1; i <= n; i ++) {
                if(to[i] == val) {
                    if(x1) {
                        x2 = i;
                    } else {
                        x1 = i;
                    }
                }
                if(!st[i]) {
                    y = i;
                }
            }
            adj[x1].push_back({y, i});
            adj[x2].push_back({y, i});
        }
    }

    vector dist(n + 1, vector(n + 1, inf));
    for(int stt = 1; stt <= n; stt ++) {
        dist[stt][stt] = 0;
        vector<vector<int>> bk(m + 1);
        bk[0].emplace_back(stt);
        for(int i = 0; i <= m; i ++) {
            while(!bk[i].empty()) {
                int x = bk[i].back();
                bk[i].pop_back();

                // 需要注意，别忘记保持仅访问最小的第一次
                if(dist[stt][x] < i) continue;

                for(auto [y, w] : adj[x]) {
                    int nd = max(dist[stt][x], w);
                    if(nd < dist[stt][y]) {
                        dist[stt][y] = nd;
                        bk[nd].emplace_back(y);
                    }
                }
            }
        }
    }

    while(q --) {
        string s;
        cin >> s;
        array<int, 3> qr;
        for(int i = 0; i < 6; i += 2) {
            qr[i / 2] = (s[i] - 48) * 50 + (s[i + 1] - 48) % 50;
        }
        if(dist[qr[0]][qr[1]] <= qr[2]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}