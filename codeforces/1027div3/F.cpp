#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
	int x, y, z;
	cin >> x >> y >> z;
	
	auto work = [&](int x) ->int {
		vector<int> fac;
		for(int i = 1; i * i <= x; i ++) {
			if(x % i == 0) {
				fac.emplace_back(i);
				if(x / i != i) {
					fac.emplace_back(x / i);
				}
			}
		}
		
		sort(fac.begin(), fac.end());
		int n = fac.size();
		vector<int> dp(n, inf);
		dp[0] = 0;
		for(int i = 0; i < n; i ++) {
			for(int j = 0; j < i; j ++) {
				if(fac[i] % fac[j] == 0 && fac[j] * z >= fac[i]) {
					dp[i] = min(dp[j] + 1, dp[i]);
				}
			}
		}
		return dp[n - 1];
	};

	int g = gcd(x, y);
	int a = work(x / g), b = work(y / g);
	if(a == inf || b == inf) {
		cout << -1 << '\n';
	} else {
		cout << a + b << '\n';
	}
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