#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n;
	cin >> n;
	vector<double> f(n + 1);			//选中的概率为p，选中的期望次数为1/p
	f[n] = 0;
	for(int i = n - 1; i >= 0; i --)
	{
		f[i] = f[i + 1] + 1.0 * n / (n - i);
	}
	printf("%.2lf\n", f[0]);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}