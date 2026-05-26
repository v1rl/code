#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}

	vector<int> sumA(n + 1);
	vector B(n + 1, vector(n + 1, 0));
	vector C(n + 1, vector(n + 1, 0));
	auto check = [&](int mid) -> bool {
		for(int i = 1; i <= n; i ++) {
			sumA[i] = (a[i] >= mid);
			sumA[i] += sumA[i - 1];
		}

		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				B[i][j] = ((sumA[j] - sumA[i - 1]) * 2 > (j - i + 1));
			}
		}

		C = B;
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				C[i][j] += C[i][j - 1];
			}
		}

		for(int j = 1; j <= n; j ++) {
			for(int i = j - 1; i >= 1; i --) {
				C[i][j] += C[i + 1][j];
			}
		}

		int sum = 0;
		for(int i = 1; i <= n; i ++) {
			for(int j = i; j <= n; j ++) {
				sum += (C[i][j] * 2 > (j - i + 1) * (j - i + 2) / 2);
			}
		}

		return sum * 2 > n * (n + 1) / 2;
	};

	int l = 1, r = 1e9;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}

	cout << l << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}