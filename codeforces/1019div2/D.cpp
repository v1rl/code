#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://codeforces.com/contest/2103/problem/D
// 保证目标位置为局部最小值
// 将所有的奇数位置倒叙放置, 偶数位置顺序放置
// 保证非目标位置不为局部最值
// 奇数保证最右边不是递减，偶数保证最右边不是递增

// 最右边是否一定存在？显然一定存在，最右边即（-1的右边）

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int mx = 0;
	int pos = -1;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		mx = max(a[i], mx);
		if(a[i] == -1) pos = i;
	}

	vector<int> ans(n + 1);
	int stt = 1, edd = n;
	int r = n;
	for(int x = 1; x <= mx; x ++)
	{
		int suf = 0;

		for(int i = 1; i <= n; i ++)
		{
			if(a[i] == x)
			{
				if(x & 1) ans[i] = edd --;
				else ans[i] = stt ++;
			}
			else if(a[i] == -1)
			{
				suf = i;
			}
		}

		int len = 0;
		for(int i = r; i > suf; i --)
			if(a[i] == x) 
				len ++;

		if(x & 1)
		{
			edd += len;
			for(int i = r; i > suf; i --)
				if(a[i] == x) 
					ans[i] = edd --;
		}
		else
		{
			stt -= len;
			for(int i = r; i > suf; i --)
				if(a[i] == x) 
					ans[i] = stt ++;
		}
	}

	ans[pos] = stt;
	for(int i = 1; i <= n; i ++)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';
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
}