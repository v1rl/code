#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

/*
因为每次连边都是连两个不同的连通块
不难得出，目标生成树最多只占所有可能性的其一
因此，我们只要用乘法算出总的可能性即可得到答案
除此之外，需要判读是否有可能构造出给定的生成树
注意到：树的子节点有多个，但父节点唯一，利用这个唯一性来判断是否有合法构造
我们按照生成树为底子维护出每个点的深度，那么每次连通块连接时，若要保证得到目标生成树，必然是一个连通块最高的节点连向其父节点
即保证一个连通块最高节点的父节点在另一个连通块中

Trick：猜测树类题目的构造时，可以往父节点唯一性上思考一下
*/
const int N = 1e6 + 10, mod = 998244353;
int p[N], siz[N]; 

int find(int x) {
	if(x != p[x]) p[x] = find(p[x]);
	return p[x];
}

i64 qmi(i64 a, i64 b) {
	i64 res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++) {
		p[i] = i;
		siz[i] = 1;
	}
	vector<array<int, 2>> a(n - 1);
	for(int i = 0; i < n - 1; i ++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}

	vector<int> fa(n + 1), dep(n + 1);
	dep[1] = 1;
	vector<vector<int>> adj(n + 1);
	for(int i = 1; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		adj[x].emplace_back(y);
		adj[y].emplace_back(x);
	} 

	queue<int> q;
	q.push(1);
	dep[1] = 1;
	while(q.size()) {
		int x = q.front();
		q.pop();
		for(auto y : adj[x]) {
			if(dep[y]) continue;
			fa[y] = x;
			dep[y] = dep[x] + 1;
			q.push(y);
		}
	}

	i64 ans = 1;
	bool f = true;
	for(auto [x, y] : a) {
		x = find(x), y = find(y);
		ans *= 1ll * siz[x] * siz[y] % mod;
		ans %= mod;
		int fx = find(fa[x]), fy = find(fa[y]);
		if(fx != y && fy != x) {
			f = false;
			break;
		}
		if(dep[x] > dep[y]) {
			swap(x, y);
		}
		p[y] = x;
		siz[x] += siz[y];
	}
	if(!f) {
		cout << 0 << '\n';
	} else {
		cout << qmi(ans, mod - 2) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}