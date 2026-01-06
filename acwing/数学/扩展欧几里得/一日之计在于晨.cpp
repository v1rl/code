#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

// https://ac.nowcoder.com/acm/contest/77448/C

int exgcd(int a, int b, int &x, int &y)
{
	if(!b)
	{
		x = 1, y = 0;
		return a;
	}
	int t = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return t;
}

void solve()
{
	// 得到ax + my = t % d - t中满足条件的最小正整数x
	// 用exgcd求解裴蜀定理的x和y
	// 将得到的答案，乘上右边式子相对gcd的倍数
	// 得到x的通解

	int t, a, m;
	cin >> t >> a >> m;
	t -= 1;
	int x, y;
	int d = exgcd(a, m, x, y);
	t = (t % d) - t;
// 	t = ((t % d - t) % m + m) % m;
	if(t < 0) t = -t;
	x *= t / d;

	int xmod = m / d;
	x = (x % xmod + xmod) % xmod;
	cout << min(x, -(x - xmod)) << '\n'; 
}

signed main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}