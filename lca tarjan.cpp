#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<int, int> PII;

const int N = 5e5 + 10;
int p[N];

int find(int x) {
	if(x != p[x]) {
		p[x] = find(p[x]);
	}
	return p[x];
}

void solve() {
    int n, m, rt;
    cin >> n >> m >> rt;

    for(int i = 1; i <= n; i ++) {
    	p[i] = i;
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; i ++) {
    	int x, y;
    	cin >> x >> y;
    	adj[x].emplace_back(y);
    	adj[y].emplace_back(x);
    }

    vector<vector<array<int, 2>>> vec(n + 1);
    for(int i = 1; i <= m; i ++) {
    	int x, y;
    	cin >> x >> y;
    	vec[x].push_back({y, i});
    	vec[y].push_back({x, i});
    }

    vector<int> ans(m + 1);
    vector<int> vis(n + 1);
   	auto dfs = [&](auto &&self, int x, int pa) -> void {
   		for(auto y : adj[x]) {
   			if(y == pa) {
   				continue;
   			}
   			self(self, y, x);
   			p[y] = x;
   		}

   		vis[x] = true;

   		for(auto [y, id] : vec[x]) {
   			if(vis[y]) {
   				ans[id] = find(y);
   			}
   		}
   	};

   	dfs(dfs, rt, -1);

   	for(int i = 1; i <= m; i ++) {
   		cout << ans[i] << '\n';
   	}
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