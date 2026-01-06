#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9 + 10;

/*
实际上，我们可以进一步发现，不需要从小到大执行
对于每个点，将它作为区间内唯一最高点的最大区间累加到答案中，随后将区间内所有点视作与当前点等高
用单调栈找到每个点左侧大于等于它的第一个点和右侧大于等于它的第一个点，借此统计答案
但要注意从左往右执行，特判右点和当前点相等时不累计的清空
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 2);
	vector<array<int, 2>> b;
	b.reserve(n);

	// 需要注意，单调栈存的是下标，要得到值记得在外面套上a[]
	vector<int> stk;
	a[0] = a[n + 1] = inf;
	stk.push_back(0);
	i64 ans = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		while(stk.size() && a[stk.back()] < a[i]) {
			stk.pop_back();
		}
		ans += i - stk.back() - 1;
		stk.push_back(i);
	}

	stk.clear();
	stk.push_back(n + 1);
	for(int i = n; i >= 1; i --) {
		while(stk.size() && a[stk.back()] < a[i]) {
			stk.pop_back();
		}
		if(a[stk.back()] != a[i]) {
			ans += stk.back() - i - 1;
		}
		stk.push_back(i);
	}
	cout << ans << '\n';
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