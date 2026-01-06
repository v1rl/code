#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
这样的环上移动问题往往和取模联系，可以得到下方式子
rmin = (t - 1 + ax) % m
而解取模问题中的位置数往往会联想到裴蜀定理和exgcd，从而将取模拆解为
ax + my + t - 1 - rmin = 0 -> ax + my = rmin - (t - 1)
这样，我们就得到了未知数rmin的约束 (rmin - (t - 1)) % gcd(a, m) == 0
其中t - 1是已知数，我们拆解取模式子得到 rmin % g = (t - 1) % g
显然，rmin和(t - 1)取模g得到的结果相同，那么不难推导出最小值rmin = (t - 1) % g
如此，ax + my = (t - 1) % g - (t - 1)
右侧全部为已知数，可以通过exgcd求解可能的x和y
*/

int exgcd(int a, int b, i64 &x, i64 &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	int t = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return t;
}

void solve() {
	int t, a, m;
	cin >> t >> a >> m;
	t -= 1;
	i64 x, y;
	int d = exgcd(a, m, x, y);
	t = (t % d) - t;

	x *= t / d;

	int xmod = m / d;
	x = (x % xmod + xmod) % xmod;
	cout << min(x, -(x - xmod)) << '\n'; 
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}