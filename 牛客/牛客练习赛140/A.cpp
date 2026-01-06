#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	if(n < m) {
		cout << -1 << '\n';
		return;
	}
	cout << s.substr(0, m) << '\n';
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