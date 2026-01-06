#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://codeforces.com/contest/1954/problem/E

/*
每次给不包含0的连续区间全体减1
转换为每次给任意连续区间加1，最终凑出题中的原始目标
借助https://www.luogu.com.cn/problem/P1969中的Trick：
每次操作可以给任意连续区间加1，将全0序列转换为目标序列的最小操作次数是序列所有大于零的差分的总和

我们将血量上取整除伤害就可以得到需要的伤害次数，这样我们就将单词求解转换为了上面的情况
我们通过数论分块找到差分的i与i-1都不变的那段伤害，并统一计算
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int mx = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}

	vector<i64> ans(mx + 2);
	for(int i = 1; i <= n; i ++) {
		for(int l = 1, r; l <= mx; l = r + 1) {
			int r1 = l >= a[i] ? mx : (a[i] - 1) / ((a[i] - 1) / l);
			int r2 = l >= a[i - 1] ? mx : (a[i - 1] - 1) / ((a[i - 1] - 1) / l);
			r = min(r1, r2);
			int w = max(0, (a[i] + l - 1) / l - (a[i - 1] + l - 1) / l);
			ans[l] += w, ans[r + 1] -= w;
		}
	}
	for(int i = 1; i <= mx; i ++) {
		ans[i] += ans[i - 1];
	}
	for(int i = 1; i <= mx; i ++) {
		cout << ans[i] << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --) {
		solve();
	}
	return 0;
}