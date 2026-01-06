#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 2e5+10;

void solve() {
	string s = "?;";
	int t = (s[0] - 48) * 50;
	t += (s[1] - 48) % 50;
	cout << t << '\n';
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