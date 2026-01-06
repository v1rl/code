#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9 + 7;

void solve()
{
	int x;
	cin >> x;
	if(x % 4 == 0)
	{
		cout << "NO" << '\n';
		return;
	}
	x --;
	vector<int> ans(32, -1);
	ans[31] = 1;
	for(int i = 31; i >= 0; i --)
	{
		if(x >> i & 1)
		{
			if(i != 0) ans[i - 1] = 1;
			else ans[i] = 0;
		} 
	}

	cout << "YES" << '\n';
	for(int i = 0; i < 32; i ++)
	{
		cout << ans[i] << ' ';
		if((i + 1) % 8 == 0) cout << '\n';
	}
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