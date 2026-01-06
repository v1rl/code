#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

/*

*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> pos(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	vector<int> st(n + 2);

	st[pos[n]] = true;
	for(int i = n - 1; i >= 1; i --){
		int cpos = pos[i];
		if(st[cpos - 1] || st[cpos + 1]) {
			st[cpos] = true;
			continue;
		} else {
			cout << "No" << '\n';
			return;
		}
	}
	cout << "Yes" << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}