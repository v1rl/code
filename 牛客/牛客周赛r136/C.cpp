#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const i64 inf = 1e18;
const int mod = 998244353;

vector<int> fact, infact;
void init(int n) {
    fact.resize(n + 1);
    infact.resize(n + 1);

    fact[0] = infact[0] = fact[1] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = 1ll * infact[i - 1] * infact[i] % mod;
    }
}

int C(i64 a, i64 b) {
    if(a < b) {
        return 0;
    }
    return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	init(n);

	int a[3] {};
	for(auto c : s) {
		if(c == 'j') {
			a[0] ++;
		} else if(c == 'o') {
			a[1] ++;
		} else {
			a[2] ++;
		}
	}

	int n1 = (n + 1) / 2, n0 = n / 2;
	if(a[0] > n1 || a[1] > n0) {
		cout << 0 << '\n';
	} else {
		cout << 1ll * C(a[2], n1 - a[0]) * fact[n0] % mod * fact[n1] % mod;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	i64 t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
}