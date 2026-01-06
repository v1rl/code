#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
相邻交换--在其他数顺序不变的情况下，将一个数放到另一个位置
跨位交换--同一个位置不会交换两次

观察是否会在同一个位置多次交换
观察是否只有一个数的顺序不对

1 5 3 2 4 


1 4 5 2 3 
*/
void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	vector<int> sum(n + 1);
	vector<int> pos;
	for(int i = 1; i <= n; i ++) {
		if(a[i] - a[i - 1] < 0) {
			sum[i] = 1;
			pos.emplace_back(i);
		}
	}

	for(int i = 1; i <= n; i ++) {
		sum[i] += sum[i - 1];
	}

	while(q --) {
		int l, r;
		cin >> l >> r;
		if(sum[r] - sum[l] > 2) {
			cout << "No" << '\n';
		} else if(sum[r] - sum[l] == 0) {
			cout << "Yes" << '\n';
		} else if(sum[r] - sum[l] == 1) {
			auto t = upper_bound(pos.begin(), pos.end(), l);
			if((*t == l + 1 || a[*t - 2] < a[*t]) || (*t == r || a[*t - 1] < a[*t + 1])) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
		} else {
			auto t = upper_bound(pos.begin(), pos.end(), l);
			auto p = t + 1;
			if(a[*t - 1] < a[*t + 1] && a[*p - 2] < a[*p]) {
				cout << "Yes" << '\n';
			} else {
				cout << "No" << '\n';
			}
		}
	}
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