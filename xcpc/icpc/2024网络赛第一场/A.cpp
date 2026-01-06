#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
建议是尝试画图解决问题
*/

void solve() {
	int lower = 0;
	int cn;
	cin >> cn;
	for(int i = 1; i < 32; i ++) {
		int x;
		cin >> x;
		if(x < cn) {
			lower ++;
		}
	}
	
	int ans;
	if(lower == 31) {
		ans = 1;
	} else if(lower >= 27) {
		ans = 2;
	} else if(lower >= 13) {
		ans = 4;
	} else if(lower >= 6) {
		ans = 8;
	} else if(lower >= 2) {
		ans = 16;
	} else {
		ans = 32;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}