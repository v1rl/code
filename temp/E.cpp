#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;


void solve() {
	int s;
	cin >> s;
	vector<int> a(8);
	for(int i = 1; i <= 7; i ++) {
		cin >> a[i];
	}

	auto check = [&](int mid) {
		vector<int> num(4);
		vector<int> b = a;
		num[1] = b[1] + b[3] + b[5] + b[7];
		num[2] = b[2] + b[6];
		num[3] = b[4];


		int y = 0;
		if(num[3] < mid) {
			vector<int> p = {6, 5, 7};
			vector<int> bl = {2, 1, 1};
			int cnt = 0;
			for(auto x : p) {
				int t = mid - num[3];
				int ct = min(b[x], t);
				num[3] += ct;
				b[x] -= ct;
				num[bl[cnt]] -= ct;

				if(x == 6) {
					y = ct;
				}

				if(num[3] == mid) {
					break;
				}
				cnt ++;
			}
		}

		if(num[2] < mid) {
			vector<int> p = {5, 3, 7};
			for(auto x : p) {
				int t = mid - num[2];
				int ct = inf;
				if(x == 5) {
					ct = min({b[x], y, t});
				} else {
					ct = min(b[x], t);
				}
				num[2] += ct;
				b[x] -= ct;
				num[1] -= ct;

				if(num[2] == mid) {
					break;
				}
			}
		}


		for(int i = 1; i <= 3; i ++) {
			if(num[i] < mid) {
				return false;
			}
		}
		return true;
	};

	int l = 0, r = s;
	while(l < r) {
		// cerr << 'h';
		int mid = (l + r + 1) >> 1;
		if(check(mid)) l = mid;
		else {
			r = mid - 1;
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