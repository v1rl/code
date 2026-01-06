#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// 左右等宽地二分
// 找相邻最多能0->1的长度，如果该长度下符合个数要求，则直接输出，否则根据还需要多少个1，继续左右等宽二分，找1的位置
// 第一段区间是带有变化但连续的1，用数学公式计算，第二段区间是离散但固定不变的1，用前缀和预处理

// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?page=1&problemSetProblemId=1781658570803388429

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;
	s = '#' + s;

	vector<int> sum0(n + 1), sum1(n + 1);
	vector<i64> sum(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		sum0[i] = sum0[i - 1] + (s[i] == '0');
		sum1[i] = sum1[i - 1] + (s[i] == '1');
		sum[i] = sum[i - 1] + (s[i] == '1' ? i : 0);
	}

	auto get = [&](int l, int pos, int r)->i64
	{
		return 1ll * (pos - l) * (pos - l + 1) / 2 + 1ll * (r - pos) * (r - pos + 1) / 2;
	};

	auto check = [&](int pos, int mid)
	{
		int l = max(1, pos - mid), r = min(n, pos + mid);
		return (sum0[r] - sum0[l - 1]) >= m;
	};

	auto check1 = [&](int pos, int rg, int mid, int nd1)
	{
		int cl = max(1, pos - rg), cr = min(n, pos + rg);
		int l = max(1, pos - mid), r = min(n, pos + mid);
		return sum1[r] - sum1[cr] + sum1[cl - 1] - sum1[l - 1] >= nd1;
	};

	auto check2 = [&](int pos, int mid)
	{
		int l = max(1, pos - mid), r = min(n, pos + mid);
		return r - l + 1 >= k;		
	};

	for(int i = 1; i <= n; i ++)
	{
		int l = 0, r = n;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(check(i, mid)) r = mid;
			else l = mid + 1;
		}
		int L = max(1, i - l), R = min(n, i + l);
		if(sum0[R] - sum0[L - 1] > m) R --;
		int nd1 = k - (R - L + 1);

		if(nd1 <= 0)
		{
			int cl = 0, cr = n;
			while(cl < cr)
			{
				int mid = cl + cr >> 1;
				if(check2(i, mid)) cr = mid;
				else cl = mid + 1;
			}
			int cL = max(1, i - cl), cR = min(n, i + cl);
			if(cR - cL + 1 > k) cR --;
			cout << get(cL, i, cR) << " \n"[i == n];
			continue;
		}

		int cur = l;
		l = l + 1, r = n;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(check1(i, cur, mid, nd1)) r = mid;
			else l = mid + 1;
		}
		int nL = max(1, i - l), nR = min(n, i + l);
		if(sum1[nR] - sum1[R] + sum1[L - 1] - sum1[nL - 1] > nd1)  nR --;
		i64 ans1 = get(L, i, R);		//中连续
		i64 ans2 = 1ll * (sum1[L - 1] - sum1[nL - 1]) * i - (sum[L - 1] - sum[nL - 1]);		//左离散
		i64 ans3 = (sum[nR] - sum[R]) - 1ll * (sum1[nR] - sum1[R]) * i;		//右离散
		cout << ans1 + ans2 + ans3 << " \n"[i == n];
	}
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
    	solve();
    }
}