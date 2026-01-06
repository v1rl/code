#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://codeforces.com/gym/105158

// 相同的数夹住的区间只能变成同一种数		----如果一个数只出现一次，它自己单独占一个区间
// 变成区间内存在的数可以让代价少1			----让这样的减少代价操作尽可能多的出现即为答案
// 求最长上升子序列，但要保证一个区间最多只给最长上升子序列贡献一次，则考虑给区间的元素倒叙排序

void solve()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> L(n + 1, n + 1), R(n + 1, -1);
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		L[a[i]] = min(L[a[i]], i);
		R[a[i]] = i;
	}

	int tot = 0;
	vector<int> d(n + 2);
	for(int i = 1; i <= n; i ++)
	{
		if(L[i] <= R[i])
		{
			tot ++;
			d[L[i]] ++;
			d[R[i]] --;
		}
	}

	for(int i = 1; i <= n; i ++)
	{
		d[i] += d[i - 1];
	}

	int lst = 1;
	for(int i = 1; i <= n; i ++)
	{
		if(d[i] == 0)
		{
			sort(a.begin() + lst, a.begin() + i + 1, greater());
			lst = i + 1;
		}
	}

	vector<int> f;
	for(int i = 1; i <= n; i ++)
	{
		int x = a[i];
		auto it = lower_bound(f.begin(), f.end(), x);
		if(it == f.end())
		{
			f.emplace_back(x);
		}
		else
		{
			*it = x;
		}
	}

	cout << tot - f.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}