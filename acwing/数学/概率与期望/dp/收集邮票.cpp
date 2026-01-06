#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
考虑期望dp
次数的期望可以很容易转移得到
价格的期望是对次数期望的求和公式，可以推公式后通过维护次数期望和次数平方的期望得到
求次数平方的期望利用二项式分解
*/

void solve() {
  	int n;
  	cin >> n;
    /*                                      //直接维护已取i个,取完全部还需要的价格g
  	vector<double> f(n + 1), g(n + 1);
  	f[n] = g[n] = 0;
  	for(int i = n - 1; i >= 0; i --)
  	{
        // f[i] = (f[i] + 1) * (i / n) + (f[i + 1] + 1) * ((n - i) / n);
  		f[i] = f[i + 1] + 1.0 * n / (n - i);
        // g[i] = (g[i] + f[i] + 1) * (i / n) + (g[i + 1] + f[i + 1] + 1) * ((n - i) / n);
  		g[i] = 1.0 * i / (n - i) * f[i] + f[i + 1] + g[i + 1] + 1.0 * n / (n - i);
  	}
  	printf("%.2lf", g[0]);
    */

    //先推柿子得到关系.维护已取i个,取完全部还需要的次数的期望和次数的平方的期望
    vector<array<double, 2>> f(n + 1);
    for(int i = n - 1; i >= 0; i --) {
        // f[i][0] = (f[i][0] + 1) * (i / n) + (f[i + 1][0] + 1) * ((n - i) / n);
        f[i][0] = f[i + 1][0] + 1.0 * n / (n - i);
        // f[i][1] = (f[i][1] + 2 * f[i][0] + 1) * (i / n) + (f[i + 1][1] + 2 * f[i + 1][0] + 1) * ((n - i) / n);
        // 需要注意，这里计算i / (n - i)时二者都是整数，需要乘1.0才能得到小数的结果
        f[i][1] = 1.0 * i / (n - i) + 2.0 * i / (n - i) * f[i][0] + (f[i + 1][1] + 2.0 * f[i + 1][0] + 1);
    }

    printf("%.2lf", (f[0][0] + f[0][1]) / 2);
    
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --) {
        solve();
    }
    return 0;
}