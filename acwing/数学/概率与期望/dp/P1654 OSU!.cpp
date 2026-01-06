#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
连续的1的期望个数
显然可以通过线性期望dp维护
问题在于三次方，这需要我们同时维护平方和立方
需要注意此处维护的立方时全体的
*/

void solve() {
	int n;
	cin >> n;
	vector<double> p(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> p[i];

	vector<array<double, 3>> f(n + 1);
	for(int i = 1; i <= n; i ++) {
		// 第i个为1的,序列尾部连续1长度的期望
		f[i][0] = (f[i - 1][0] + 1) * p[i];
		// 第i个为1的,序列尾部连续1长度平方的期望
		f[i][1] = (f[i - 1][1] + 2 * f[i - 1][0] + 1) * p[i];
		// 注意，这里与前两个不同，前i个中,第i个任意的,序列全体连续1长度立方的期望
		f[i][2] = f[i - 1][2] + (3 * f[i - 1][1] + 3 * f[i - 1][0] + 1) * p[i];		
	}
	printf("%.1lf", f[n][2]);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    while(t --) {
        solve();
    }
    return 0;
}