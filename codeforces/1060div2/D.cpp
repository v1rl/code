#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*
每次移动都会改变深度的奇偶,删除时只能删除非当前深度奇偶性的点
默认最坏地往下走,为了避免堵死路,我们总是考虑去删除当前深度+1的点
如果当前不存在*当前深度+1的点,我们再走一次,此时深度一定-1,然后便删除当前深度的点

最开始,我们把终点到1路径的所有点存储起来
每当我们走到这样的点时,首先把它的父节点删掉
只有这样的节点同深度的点全部删光时,我们才能确定当前一定走到路径点,并执行删除其父节点的操作
*/

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	}

	vector<int> p(n + 1);
	vector<int> dep(n + 1);
	vector<vector<int>> ds(n + 1);

	dep[1] = 1;
	queue<int> q;
	q.push(1);
	while(q.size()) {
		int x = q.front();
		q.pop();
		for(auto y : adj[x]) {
			if(dep[y]) {
				p[x] = y;
				continue;
			}
			dep[y] = dep[x] + 1;
			q.push(y);
		}
	}

	int x = n;
	vector<int> st(n + 1);
	vector<int> pth;
	while(x != 1) {
		st[x] = true;
		pth.emplace_back(x);
		x = p[x];
	}
	pth.emplace_back(1);
	reverse(pth.begin(), pth.end());
	st[1] = true;

	for(int i = 1; i <= n; i ++) {
		if(!st[i]) {
			ds[dep[i]].emplace_back(i);
		}
	}
	vector<int> pos(n + 1);

	int cur = 1;

	int tar = dep[n];
	int hs = 1;

	vector<array<int, 2>> ans;
	bool f = false;
	while(1) {
		if(hs == tar) {
			break;
		}

		while(cur == hs && pos[cur + 1] == ds[cur + 1].size()) {
			ans.push_back({1, 0});
			hs ++;
			cur ++;
			if(hs == tar) {
				f = true;
				break;
			}
			ans.push_back({2, pth[hs - 2]});
		}
		if(f) {
			break;
		}

		if(pos[cur + 1] < ds[cur + 1].size()) {
			ans.push_back({1, 0});
			cur ++;
		} else {
			ans.push_back({1, 0});
			cur --;
		}

		if(pos[cur + 1] < ds[cur + 1].size()) {
			ans.push_back({2, ds[cur + 1][pos[cur + 1]]});
			pos[cur + 1] ++;
		}
	}

	cout << ans.size() << '\n';
	for(auto [c, d] : ans) {
		if(d) {
			cout << c << ' ' << d << '\n';
		} else {
			cout << c << '\n';
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
		// cout << '\n';
	}
}