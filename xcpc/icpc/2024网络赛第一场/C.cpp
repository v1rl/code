#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
可将题面转换为二分图的完全匹配方案数问题
注意到：将本题写成矩阵形式，矩阵的per即为二分图完全匹配数
注意到：mod2意义下矩阵的per等于矩阵的det
问题转换为求mod2意义下矩阵的det
注意到：mod2意义下矩阵的行列式只有可能为0或1，不需要特意去求行列式，只需要判断mod2意义下该行列式是否为0
注意到：若行列式为0，该矩阵线性相关，即其中一个向量可被其他向量表示
问题转换为求一个矩阵是否线性相关
注意到：因为题目给定的都是一个范围，所以每个向量的1都是连续的，通过相邻相加，我们可以很方便地得到每个向量仅有l - 1为-1，r位置为1的行列式
注意到：将这样的l - 1和r看作一条无向边构造成一个无向图，只要途中有环，则成环边对应行线性相关，即该矩阵线性相关，det为0
*/
const int N = 1e6 + 10;
int p[N];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n + 1; i ++) {
		p[i] = i;
	}
	bool f = true;
	for(int i = 1; i <= n; i ++) {
		int l, r;
		cin >> l >> r;
		l = find(l), r = find(r + 1);
		if(l == r) {
			f = false;
		}
		p[r] = l;
	}

	cout << (f ? 1 : 0) << '\n';
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
