#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

/*
找到所有异或和就是两点异或的对
这样的对一定至少有n - 1个
如果超过n - 1个，必然存在中间段为0，
*/


void solve() {
	int n;
	cin >> n;
	vector<int> to(n + 1), ori(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> to[i];
		ori[to[i]] = i;
	}

	vector<int> st(n + 1);
	vector<int> ans(n + 1);
	for(int i = 1; i <= n; i ++) {
		vector<int> res;
		if(!st[i]) {
			int stt = i;
			int x = i;
			while(to[x] != stt) {
				x = to[x];
				res.emplace_back(x);
				st[x] = true;
			}
		}
		int l = 0, r = 1e9;

		auto check = [&](int x) {
			
		}

		while(l < r) {
			int mid = l + r >> 1;
			if(check(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
	}
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