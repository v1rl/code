#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
根据题目，我们很自然地想到去用dp维护概率或期望
但问题在于，我们想要确定当前状态是否能释放魔法，需要保证前7个选择不同
也就是说我们转移时无法依赖之前的状态，而是依赖之前的选择
这也就没法用dp了

于是，我们考虑推式子
因为7次属性各使用一次，我们可以很容易判断出第七次能使用技能的期望E(7)
注意到：在第7次之后，释放技能的期望与次数无关
所以，我们求到第七次释放技能的期望后，乘以总次数-6即可

Trick：如果题目限制下的状态无法依赖之前的状态得到，而是要依赖一些其他选择，本题就无法使用dp，至少无法使用目前所想的dp方式
*/

void solve() {
	int a[8];
	int sum = 0;
	for(int i = 1; i <= 7; i ++) {
		cin >> a[i];
		sum += a[i];
	}

	if(sum < 7) {
		cout << "0.000" << '\n';
		return;
	}
	double ans = 1.0;
	int t = 1;
	for(int i = 1; i <= 7; i ++) {
		ans *= 1.0 * a[i] / (sum - i + 1);
		t *= i;
	}
	ans *= t;
	ans *= (sum - 6);
	printf("%.3lf", ans);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int t;
	t = 1;
	while(t --)
	{
		solve();
	}
}