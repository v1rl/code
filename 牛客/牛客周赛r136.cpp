#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 mod = 1e9 + 7;
const i64 inf = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	set<array<i64, 2>> S;
	vector<i64> a(n);
	for(i64 i = 0; i < n; i ++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	i64 lst = a[0];
	i64 l = a[0];
	for(i64 i = 1; i < n; i ++) {
		if(a[i] != lst + 1) {
			S.insert({l, a[i - 1] + 1});
			l = a[i];
		}
		lst = a[i];
	}
	S.insert({l, a[n - 1] + 1});

	while(m --) {
		i64 op, stt, len;
		cin >> op >> stt >> len;

		if(op == 1) {
			auto s = S.upper_bound({stt, inf});
			if(s != S.begin() && (*prev(s))[1] > stt) {
				s --;
			}

			auto check = [&](i64 mid) {
				int cnt = 0;
				auto cur = s;
				while(cur != S.end()) {
					auto [l, r] = *cur;
					if(l >= mid) {
						break;
					}
					cnt += min(r, mid) - max(l, stt);
					cur ++;
				}
				return cnt >= mid - (stt + len);
			};

			auto work = [&](i64 x) {
				vector<array<i64, 2>> add;
				while(s != S.end()) {
					auto [l, r] = *s;
					if(l < stt) {
						s = S.erase(s);
						add.push_back({l, stt});
					} else if(r < x) {
						s = S.erase(s);
					} else {
						break;
					}
				}
				for(auto [l, r] : add) {
					S.insert({l, r});
				}
				if(stt + len < x) {
					S.insert({stt + len, x});
				}
			};

			i64 l = stt + len;
			i64 r = l + n;
			while(l < r) {
				i64 mid = (l + r + 1) / 2;
				if(check(mid)) {
					l = mid;
				} else {
					r = mid - 1;
				}
			}
			work(l);
		} else {
			auto s = S.upper_bound({stt, inf});
			if(s == S.begin()) {
				continue;
			}
			s --;

			auto check = [&](i64 mid) {
				int cnt = 0;
				auto cur = s;
				while(1) {
					auto [l, r] = *cur;
					// cerr << l << ' ' << r << '\n';
					if(r <= mid + 1) {
						break;
					}
					cnt += min(r - 1, stt) - max(l, mid + 1) + 1;
					// cerr << cnt << '\n';
					if(cur == S.begin()) {
						break;
					}
					cur --;
				}
				return cnt >= stt - len - mid;
			};

			auto work = [&](i64 x) {
				vector<array<i64, 2>> add;
				while(1) {
					auto [l, r] = *s;

					auto ns = s;
					bool f = false;
					if(s != S.begin()) {
						f = true;
						ns = prev(s);
					}

					if(r > stt + 1) {
						S.erase(s);
						add.push_back({stt + 1, r});
					} else if(l > x) {
						S.erase(s);
					} else {
						break;
					}
					if(f) {
						s = ns;
					} else {
						break;
					}
				}
				for(auto [l, r] : add) {
					S.insert({l, r});
				}
				if(x + 1 < stt - len + 1) {
					S.insert({x + 1, stt - len + 1});
				}
			};

			i64 r = stt - len;
			i64 l = r - n;
			while(l < r) {
				i64 mid = (l + r) / 2;
				if(check(mid)) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}

			work(l);
		}
	}


	for(auto [l, r] : S) {
		// cout << l << ' ' << r << '\n';
		for(int i = l; i < r; i ++) {
			cout << i << ' ';
		}
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	i64 t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}