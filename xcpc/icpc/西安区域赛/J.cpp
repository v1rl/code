#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*

*/
struct Node {
	int w = 1e9 + 10;
	int x;
};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> w[i];
	}
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	vector<int> dep(n + 1);
    vector<array<int, 20>> f(n + 1);
    dep[1] = 1;
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int x = q.front();
        q.pop();

        for(auto y : adj[x])
        {
            if(dep[y]) continue;
            dep[y] = dep[x] + 1;
            f[y][0] = x;
            for(int i = 1; i <= 19; i ++)
                f[y][i] = f[f[y][i - 1]][i - 1];
            q.push(y);
        }
    }
    
    auto lca = [&](int x, int y)->int {
        if(dep[x] > dep[y]) swap(x, y);
        for(int i = 19; i >= 0; i --)
            if(dep[f[y][i]] >= dep[x])
                y = f[y][i];
        if(x == y) return x;
        for(int i = 19; i >= 0; i --)
            if(f[y][i] != f[x][i])
                x = f[x][i], y = f[y][i];
        
        return f[x][0];
    };

	vector<int> nw(n + 1);
	vector<array<Node, 2>> mn(n + 1);
	auto dfs1 = [&](auto &&self, int x, int p) -> void{
		for(auto y : adj[x]) {
			if(y == p) {
				continue;
			}
			self(self, y, x);
			if(nw[y] < mn[x][0].w) {
				mn[x][1].w = mn[x][0].w;
				mn[x][1].x = mn[x][0].x;
				mn[x][0].w = nw[y];
				mn[x][0].x = y;
			} else if(nw[y] < mn[x][1].w) {
				mn[x][1].w = nw[y];
				mn[x][1].x = y;
			}
		}
		nw[x] = min(w[x], mn[x][0].w + mn[x][1].w);
	};

	dfs1(dfs1, 1, -1);

	vector<i64> sumw(n + 1);
	auto dfs2 = [&](auto &&self, int x, int p) ->void{
		for(auto y : adj[x]) {
			if(y == p) {
				continue;
			}
			if(y == mn[x][0].x) {
				sumw[y] = sumw[x] + mn[x][1].w;
			} else {
				sumw[y] = sumw[x] + mn[x][0].w;
			}
			self(self, y, x);
		}
	};

	dfs2(dfs2, 1, -1);

	while(m --) {
		int x, y;
		cin >> x >> y;
		if(lca(x, y) == y) {
			cout << sumw[x] - sumw[y] << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}