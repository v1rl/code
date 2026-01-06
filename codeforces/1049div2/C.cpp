#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5 + 10;
const i64 inf = 1e10 + 10;

/*
r - l都是正收益
两个人做同一对[l, r]会不断增长，B会避免这种情况
A，偶数项最大和奇数项最小做交换
B，奇数项最大和偶数想最小做交换

A发现无论如何都会降低而直接停止
或者，B会在A执行操作后停止
但是因为r - l的存在，最大增量不能简单地用偶数最大与奇数最小交换
在最大基础上考虑向左向右移动 (X)

O(n)遍历扫一边，同时维护左奇右偶(左加右减)和左偶右奇(左减右加)的情况，每次以当前位置为右侧点，当前维护的最小值为左侧点
如此可保证最优解一定可以在遍历中被访问到
需要注意维护过程中下标i对维护的影响，并根据i对维护和计算做出对应处理
*/

void solve() {
	int n;
	cin >> n;

	i64 res = 0;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		if(i & 1) {
			res -= a[i];
		} else {
			res += a[i];
		}
	}

	int c;
	if(n & 1) {
		c = n - 1;
	} else {
		c = n - 2;
	}

	/*
	维护的奇数项对应的是左加右减，此时变量中的a[i]越大越好，i越小越好
	若维护最大值，我们用a[i] * 2 - i
	若维护最小值，我们用-a[i] + i，并在之后使用时相对应地取反
	*/
	// i64 min_odd = inf;
	i64 max_odd = 0;
	i64 min_even = inf;
	i64 init = res;
	i64 ans = res + c;
	for(int i = 0; i < n; i ++) {
		if(i & 1) {
			ans = max(ans, init + a[i] * 2 + i - min_even);
			// min_odd = min(min_odd, -a[i] * 2 + i);
			max_odd = max(max_odd, a[i] * 2 - i);
		} else {
			// ans = max(ans, init - min_odd - a[i] * 2 + i);
			ans = max(ans, init + max_odd - a[i] * 2 + i);
			min_even = min(min_even, a[i] * 2 + i);
		}
	}

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	// cout << 4284 % (42 + 84) << "\n";
}