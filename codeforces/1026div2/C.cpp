#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

// 按照最低要求执行
// 按照最高约束限制可使用的-1个数

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<array<int, 2>> rg(n + 1);
	vector<int> num;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
		if(a[i] == -1) {
			num.emplace_back(i);
		}
	}
	for(int i = 1; i <= n; i ++) {
		cin >> rg[i][0] >> rg[i][1];
	}
	int k = 0;

	int ht = 0;
	int mx = 0;
	for(int i = 1; i <= n; i ++) {
		auto [l, r] = rg[i];
		if(a[i] == 1) {
			ht ++;
		} else if(a[i] == -1) {
			mx ++;
		}

		if(ht < l) {
			if(ht + mx < l) {
				cout << -1 << '\n';
				return;
			}
			for(int j = ht; j < l; j ++) {
				a[num[k]] = 1;
				k ++;
			}
			mx -= l - ht;
			ht = l;
		} else if(ht > r) {
			cout << -1 << '\n';
			return;
		}
		int t = r - ht;
		if(t < mx) {
			k += mx - t;
			mx = t;
		}
	}

	for(int i = 1; i <= n; i ++) {
		if(a[i] == -1) {
			cout << 0 << ' ';
		} else {
			cout << a[i] << ' ';
		}
	}
	cout << '\n';
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