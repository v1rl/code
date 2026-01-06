#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
const int N = 2e5+10, inf = 1e18;
/*
6 6 2 4 3 0 1 8
5 5 2 4 3 0 1 5
6 6 2 4 3 0 1 6
5 5 2 4 3 0 1 5

6 6 2 4 4 3 3 0 1 8
5 5 2 5 5 5 5 0 1 5
3 3 2 3 3 3 3 0 1 3
4 4 2 4 4 4 4 0 1 4

某个数据出现两次且是有效数据，一次执行会让所有该数据加1
之后，所有连续的+1都回到第一个+1的起点位置
之后，起点+1，二者轮换
*/

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<int> st(n + 1);
	for(int i = 0; i < n; i ++) {
		cin >> a[i];
		st[a[i]] ++;
	}
	int cnt = 0;
	for(int i = 0; i <= n; i ++) {
		if(st[i]) {
			cnt ++;
		} else {
			break;
		}
	}
	vector<int> ans(3);
	int mn = cnt;
	int num = 0;
	for(int i = 0; i < n; i ++) {
		if(a[i] < cnt) {
			if(st[a[i]] > 1) {
				ans[0] += cnt;
				mn = min(mn, a[i]);
			} else {
				ans[0] += a[i];
			}
		} else {
			ans[0] += cnt;
			num ++;
		}
	}

	if(mn != cnt) {
		for(int i = 0; i < n; i ++) {
			if(a[i] >= mn) {
				ans[1] += mn;
			} else {
				ans[1] += a[i];
			}
		}

		for(int i = 0; i < n; i ++) {
			if(a[i] >= mn) {
				ans[2] += mn + 1;
			} else {
				ans[2] += a[i];
			}
		}		
	} else {
		if(num > 1) {
			for(int i = 0; i < n; i ++) {
				if(a[i] >= mn) {
					ans[1] += mn + 1;
				} else {
					ans[1] += a[i];
				}
			}			
		} else {
			for(int i = 0; i < n; i ++) {
				if(a[i] >= mn) {
					ans[1] += mn;
				} else {
					ans[1] += a[i];
				}
			}
		}

		for(int i = 0; i < n; i ++) {
			if(a[i] >= mn) {
				ans[2] += mn;
			} else {
				ans[2] += a[i];
			}
		}	
	}

	// for(int i = 0; i < 3; i ++) {
	// 	cout << ans[i] << ' ';
	// }
	// cout << '\n';

	if(k == 1) {
		cout << ans[0] << '\n';
	} else {
		k --;
		if(k & 1) {
			cout << ans[1] << '\n';
		} else {
			cout << ans[2] << '\n';
		}
	}

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