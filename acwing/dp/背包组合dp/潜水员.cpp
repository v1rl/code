#include <bits/stdc++.h>
using namespace std;
const int N = 22, M = 80;
int f[N][M];

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int m1, m2, n;
	cin >> m1 >> m2 >> n;

	vector<int> v1(n + 1);
	vector<int> v2(n + 1);
	vector<int> w(n + 1);
	for(int i = 1; i <= n; i ++) cin >> v1[i] >> v2[i] >> w[i];

	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = m1; j >= 0; j --)
		{
			for(int k = m2; k >= 0; k --)
			{
				f[j][k] = min(f[j][k], f[max(0, j - v1[i])][max(0, k - v2[i])] + w[i]);
			}
		}
	}

	cout << f[m1][m2] << '\n';
}