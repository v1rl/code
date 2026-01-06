#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<array<int, 2>> q;
	q.reserve(n);
	for(int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		q.push_back({x, y});
	}

	sort(q.begin(), q.end());

	vector<int> op{0, 1};
	for(auto [x, y] : q) {
		int ch = x & 1;
		if(op[ch] != (y & 1)) {
			m --;
			swap(op[0], op[1]);
		}
	}

	cout << m << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}