#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// 通过乘10的x次方，保证前面的数不变
// n个连续的数里面，一定有一个数可以被n整除

// 先构造出目标，再考虑补全构造

void solve()
{
	int n, k;
	cin >> n >> k;
	i64 s = 0;
	for(int i = 1; i <= 9; i ++)
		s = s * 10 + i;
	s = s * 10 + k;

	int t = n;
	while(t)
	{
		s *= 10;
		t /= 10;
	}

	cout << (s + n - 1) / n << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}