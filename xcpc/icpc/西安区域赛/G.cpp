#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int s = 0;
	for(int i = 0; i < n; i ++) {
		if(s >= a[i]) {
			s ++;
		} else {
			s --;
		}
	}
	cout << s << ' ';
	s = 0;
	reverse(a.begin(), a.end());
	for(int i = 0; i < n; i ++) {
		if(s >= a[i]) {
			s ++;
		} else {
			s --;
		}
	}
	cout << s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}