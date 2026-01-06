#include<bits/stdc++.h>
using namespace std;
#define int long long
using i64 = long long;
using PII = pair<int, int>;
const int inf = 1e9;

/*
题目较乱时，建议画图辅助考虑做法
1.二分答案后，根据当前值是否大于mid得到一维bool数组，然后前缀和预处理，最后判断范围A[1, n]和是否大于总数的一半(needone)
查找大范围B[l, r]内所有小范围数对A[nl, nr](l<=nl<=nr<=r)的中位数组成的序列的中位数

2.根据1.范围A[l, r]和是否大于总数的一半得到一个二维的bool数组B[][](needAll)，
然后做倒三角累加处理(和第一步里面的前缀和后sum[r]-sum[l - 1]是同类型操作，最后判断B[1, n]是否大于总数的一半(needone)

3.得到B[l, r]的bool数组后(needAll)，累加得到范围C[1, n]是否大于总数的一半(needone)
*/

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

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	// cin >> t;
	while(t --) {
		solve();
	}
	return 0;
}