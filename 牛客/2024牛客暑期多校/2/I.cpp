#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t -- )
	{
		int m, n;
		cin >> m >> n;
		int a = 0, b = 0;
		for(int i = 0; i < n; i ++)
		{
			int x;
			cin >> x;
			int l = x, r = m - x;
			a = max(a, min(l, r));
			b = max(b, max(l, r));
		}
		cout << a << ' ' << b << "\n";
	}
}