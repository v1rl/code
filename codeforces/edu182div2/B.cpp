#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
不存在
只有一个
两个及以上
第一个和最后一个
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int num = 0;
	int l = 0, r = -1;
	int tl = 0, tr = -1;
	vector<int> st(n + 1);
	int pos = 0;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		st[a[i]] = true;
		if(a[i] == 0) {
			pos = i;
		}

		if(a[i] != i || a[i] == 0) {
			if(l == 0) {
				l = i;
			}
			r = i;
		}

		if(a[i] != 0 && a[i] != i) {
			if(tl == 0) {
				tl = i;
			}
			tr = i;
		}

		if(a[i] == 0) {
			num ++;
		}
	}
	if(num == 0) {
		cout << r - l + 1 << '\n';
	} else if(num == 1) {
		int t = 0;
		for(int i = 1; i <= n; i ++) {
			if(!st[i]) {
				t = i;
				break;
			}
		}
		if(pos == t) {
			cout << tr - tl + 1 << '\n';
		} else {
			cout << r - l + 1 << '\n';
		}
	} else if(num > 1) {
		cout << r - l + 1 << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}