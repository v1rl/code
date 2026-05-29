#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
const int inf = 1e9 + 7;

void solve() {
	vector<int> a(6);
	for(int i = 1; i <= 5; i ++) {
		cin >> a[i];
	}

	int ans = 0;
	int t = min(a[1], a[5]);
	ans += t;
	a[1] -= t;
	a[5] -= t;

	t = min(a[2], a[4]);
	ans += t;
	a[2] -= t;
	a[4] -= t;

	ans += a[3] / 2;
	a[3] %= 2;

	if(a[1] && a[2]) {
		if(a[3]) {
			ans ++;
			a[3] --, a[1] --, a[2] --;
		}
		ans += a[2] / 3;
		a[1] += a[2] % 3 * 2;
		ans += a[1] / 6;
	} else if(a[1] && a[4]) {
		int t = min(a[1] / 2, a[4]);
		ans += t;
		a[4] -= t, a[1] -= 2 * t;
		if(a[4]) {
			if(a[1]) {
				a[4] ++;
			}
			if(a[3]) {
				a[4] ++;
			}
			ans += a[4] / 3;
		} else if(a[1]) {
			if(a[3] && a[1] >= 3) {
				ans ++;
				a[1] -= 3;
			}
			ans += a[1] / 6;
		}
	} else if(a[5] && a[2]) {
		int t = min(a[5], a[2]);
		ans += t;
		a[5] -= t, a[2] -= t;
		if(a[5]) {
			if(a[3]) {
				a[5] --;
				ans ++;
			}
			ans += a[5] / 2;
		} else if(a[2]) {
			if(a[3]) {
				a[2] ++;
			}
			ans += a[2] / 3;
		}
	} else if(a[5] && a[4]) {
		int t = min(a[5], a[4]);
		ans += t;
		a[5] -= t, a[4] -= t;
		if(a[5]) {
			if(a[3]) {
				a[5] --;
				ans ++;
			}
			ans += a[5] / 2;
		} else if(a[4]) {
			if(a[3]) {
				a[4] ++;
			}
			ans += a[4] / 3;
		}
	} else {
		if(a[1]) {
			if(a[3] && a[1] >= 3) {
				ans ++, a[1] -= 3;
			}
			ans += a[1] / 6;
		} else if(a[2]) {
			if(a[3]) {
				a[2] ++;
			}
			ans += a[2] / 3;
		} else if(a[4]) {
			if(a[3]) {
				a[4] ++;
			}
			ans += a[4] / 3;
		} else if(a[5]) {
			if(a[3]) {
				a[5] ++;
			}
			ans += a[5] / 2;
		}
	}

	cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}