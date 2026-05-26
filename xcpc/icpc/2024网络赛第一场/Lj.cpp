#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 1e9;

/*
Trick：桶优化dijk / MST+DFS+LCA跑最小瓶颈路
Trick：两个排列(下标排列和值排列)的连接将形成若干个环，因而在判断连通性上我们可以将边视作双向边，
从而用并查集避免一些需要用SCC的操作
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
            int t = (x - 48) * 50 + (y - 48) % 50;
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