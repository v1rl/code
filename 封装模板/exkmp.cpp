#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> zFunction(string &s) {
	int n = s.size();
	vector<int> z(n);
	for(int i = 1, l = 0, r = 0; i < n; i ++) {
		if(i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}

		while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			z[i] ++;
		}

		if(i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

void solve() {
	string s;
	cin >> s;
	vector z = zFunction(s);
    for(int i = 0; i < s.size(); i ++) {
    	cout << z[i] << " \n"[i == s.size() - 1];
    }
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --) {
		solve();
	}
	return 0;
}