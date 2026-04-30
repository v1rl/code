#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9, mod = 998244353;

int tonum(char c) {
	if(c == 'C') {
		return 0;
	}
	if(c == 'W') {
		return 1;
	}
	return 2;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = '#' + s;
	int sl = -1, sr = -1;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == s[i + 1]) {
			if(sl == -1) {
				sl = i + 1;
			}
			sr = i;
		}
	}

	if(sl == -1) {
		cout << "Beautiful" << '\n';
		return;
	}

	vector pre(3, vector(n + 1, 0));
	for(int i = 1; i <= n; i ++) {
		for(int c = 0; c < 3; c ++) {
			pre[c][i] = pre[c][i - 1] + (c == tonum(s[i]));
		}
	}

	auto check = [&](int l, int r) {
		bool ok = true;
		for(int c = 0; c < 3; c ++) {
			int cnt = pre[c][r] - pre[c][l - 1];
			int res = cnt * 2 - (r - l + 1);
			res += (l - 1 >= 1 && tonum(s[l - 1]) == c);
			res += (r + 1 <= n && tonum(s[r + 1]) == c);
			ok &= res <= 1;
		}
		return ok;
	};

	int tl = -1, tr = -1, tlen = n + 1;
	for(int l = 1, r = sr; l <= sl; l ++) {
		while(r <= n) {
			if(check(l, r)) {
				int len = r - l + 1;
				if(len < tlen) {
					tlen = len;
					tl = l;
					tr = r;
				}
				break;
			} else {
				r ++;
			}
		}
	}

	if(tl == -1) {
		cout << "Impossible" << '\n';
		return;
	}

	cout << "Possible" << '\n';
	cout << tl << ' ' << tr << '\n';
	string ans = s;
	vector<int> cnt(3);

	for(int c = 0; c < 3; c ++) {
		cnt[c] = pre[c][tr] - pre[c][tl - 1];
	}

	auto ansCheck = [&](int C, int l, int r) {
		bool ok = true;
		for(int c = 0; c < 3; c ++) {
			int res = cnt[c] * 2 - (r - l + 1);
			res += (r + 1 <= n && tonum(s[r + 1]) == c);
			res += (c == C);

			ok &= res <= 1;
		}
		return ok;
	};

	for(int i = tl; i <= tr; i ++) {
		for(int c = 0; c < 3; c ++) {
			if(cnt[c] && (i - 1 < 1 || tonum(ans[i - 1]) != c)) {
				cnt[c] --;
				if(ansCheck(c, i + 1, tr)) {
					ans[i] = "CWP"[c];
					break;
				}
				cnt[c] ++;
			}
		}
	}

	for(int i = 1; i <= n; i ++) {
		cout << ans[i];
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
	while(t --) {
		solve();
	}
}