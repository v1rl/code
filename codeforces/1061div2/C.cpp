#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*
删除总是删除最小的数
x1=p,
x3=2*p if(4 * p <= x)

p < x < 4 * p
2 * p、 3 * p
中间部分只有2 * p 和 3 * p
求出2 * p和3 * p的总数，并和区间总数做比较
*/

const int N = 2e5 + 10;
int st[N];

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int mx = 0;
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		st[a[i]] ++;
		mx = max(mx, a[i]);
	}
	sort(a.begin(), a.end());
	for(int i = mx; i >= 2; i --) {
		int pos1 = lower_bound(a.begin(), a.end(), i) - a.begin();
		int pos2 = lower_bound(a.begin(), a.end(), 4 * i) - a.begin();
		pos2 --;

		// if(i == 4) {
		// 	cout << pos1 << ' ' << pos2 << '\n';
		// }
		int d = max(pos2 - pos1 + 1, 0);
		if(k < pos1) {
			continue;
		}

		int t = st[i];
		if(i * 2 <= mx) {
			t += st[i * 2];
		}
		if(i * 3 <= mx) {
			t += st[i * 3];
		}

		// if(i == 4) {
		// 	cout << t << '\n';
		// }
		if(d - t <= k - pos1) {
			cout << i << '\n';
			for(int i = 0; i < n; i ++) {
				st[a[i]] = 0;
			}
			return;
		}
	}
	cout << 1 << '\n';
	for(int i = 0; i < n; i ++) {
		st[a[i]] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}