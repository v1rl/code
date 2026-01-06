#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;
#define int long long
const i64 inf = 1e18;
const int N = 505;
int g[N][N];
int f[N][2][N];

// 不能重复访问
// 向右转移时，不会面临级数困境
// 只有向下转移时，才会消耗 
// 列、k、行 
 

void solve() {
	int n, m;
	cin >> n >> m;
	int stt, edd;
	cin >> stt >> edd;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> g[i][j];
		}
	} 
	for(int k = 0; k <= n; k ++) {
		for(int i = 0; i <= n; i ++) {
			for(int j = 0; j <= 1; j ++) {
				f[i][j][k] = -inf;
			} 
		}
	}
	
	f[stt][1][1] = g[stt][1];

	int ans = -inf;
	for(int j = 1; j <= m; j ++) {
		int t = (j & 1);
		for(int k = 1; k <= n; k ++) {
			for(int i = 1; i <= n; i ++) {
				int lrow = (i - 1 == 0) ? n : i - 1;
				f[i][t][k] = max(f[i][t][k], f[lrow][t][k - 1] + g[i][j]);
				f[i][t ^ 1][1] = max(f[i][t ^ 1][1], f[i][t][k] + g[i][j + 1]);
			}
			if(j == m) ans = max(ans, f[edd][m & 1][k]);
		}
		for(int i = 0; i <= n; i ++) {
			for(int k = 0; k <= n; k ++) {
				f[i][t][k] = -inf;
			} 
		}
	} 
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t = 1;
//	cin >> t;
	while(t --) {
		solve();
	} 
	return 0;
}