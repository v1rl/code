#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

/*
显然，暴力判断不可取，x的选取不符合单调性或二次函数，同时也没有好的贪心
目标值是除以一个数上取整，考虑能不能把一系列数放在一块求解
考虑数论分块，对于一个数c[i]有多少个可能的x会得到相同的结果，但n维数论分块并不能有什么优化
因为本题c[i]的范围有限，可以作为数组的下标
我们可以通过预处理很容易地得到某个数的出现次数，以及某个数范围中数的出现总次数
考虑反过来，对于一个数x有多少个可能的c[i]会得到相同的结果，即(c[i] * (x - 1), c[i] * x]
这种按大小为x的块的方式枚举的复杂度为调和级数O(nlog(n))

Trick：值大且少时考虑正向数论分块，值小且多时考虑反向调和级数分块
*/

void solve() {
	int n, y;
	cin >> n >> y;
	int maxA = 0;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		maxA = max(a[i], maxA);
	}
	vector<int> bk(maxA + 1);
	for(int i = 1; i <= n; i ++) {
		bk[a[i]] ++;
	}

	// 需要注意，利用桶解题时，for不要习惯性地以n为上界，要注意上界可以是n 还是只能是数据最大值maxA
	for(int i = 1; i <= maxA; i ++) {
		bk[i] += bk[i - 1];
	}

	if(maxA == 1) {
		cout << n << '\n';
		return;
	}
	i64 ans = -1e18;
	for(int x = 2; x <= maxA; x ++) {
		i64 cans = 0;
		for(int k = 0; k <= maxA; k += x) {
			int v = k / x + 1;
			int num = bk[min(k + x, maxA)] - bk[k];
			cans += 1ll * v * num - 1ll * max(num - (bk[v] - bk[v - 1]), 0) * y;
		}
		ans = max(ans, cans);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}