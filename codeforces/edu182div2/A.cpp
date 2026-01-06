#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}


	for(int l = 1; l <= n; l ++) {
		for(int r = l + 1; r < n; r ++) {
			int s1 = 0, s2 = 0, s3 = 0;
			for(int i = 1; i <= l; i ++) {
				s1 += a[i];
			}
			for(int i = l + 1; i <= r; i ++) {
				s2 += a[i];
			}
			for(int i = r + 1; i <= n; i ++) {
				s3 += a[i];
			}
			s1 %= 3, s2 %= 3, s3 %= 3;
			if(s1 == s2 && s1 == s3 && s2 == s3) {
				cout << l << ' ' << r << '\n';
				return;
			} else if(s1 != s2 && s1 != s3 && s2 != s3) {
				cout << l << ' ' << r << '\n';
				return;
			}
		}
	}

	cout << 0 << ' ' << 0 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}