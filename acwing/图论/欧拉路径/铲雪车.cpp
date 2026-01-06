#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
	ios::sync_with_stdio(false), cin.tie(0);
	int n, m;
	cin >> n >> m;
	int x1, y1, x2, y2;
	double res = 0;
	while(cin >> x1 >> y1 >> x2 >> y2)
	{
		i64 x = x1 - x2, y = y1 - y2;
		res += sqrt(x * x + y * y);
	}
	int minutes = round(res / 20000 * 120);
	printf("%d:%02d",minutes / 60, minutes % 60);
}