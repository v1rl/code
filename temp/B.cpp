#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
m位拆位，每一位的和是偶数

*/

void solve() {
	int s;
	cin >> s;
	vector<int> a(8);
	for(int i = 1; i <= 7; i ++) {
		cin >> a[i];
	}

	auto check = [&](int mid) {
		

		for(int x = 1; x <= 3; x ++) {
			if(x == 1) {

			}
		}
	}

	int l = 0, r = s;
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else {
			l = mid + 1;
		}
	}
	cout << l << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}