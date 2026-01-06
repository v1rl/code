#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5+10, inf = 1e18;

void solve() {
	i64 a, b;
	cin >> a >> b;

	i64 ans = 0;

	while(1) {
		if((a + b) % 2 == 0) {
			i64 t = b;
			while(t % 2 == 0) {
				t /= 2;
			}
			ans = max({ans, a + b, a * t + b / t});
		}
		if(b % 2 == 0) {
			b /= 2;
			a *= 2;			
		} else {
			break;
		}
	}
	cout << (ans ? ans : -1) << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}