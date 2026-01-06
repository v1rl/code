#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1010;
int f[N];

// https://www.acwing.com/problem/content/description/237/

int sg(int x)
{
	if(f[x] != -1) return f[x];
	vector<int> nums;
	nums.emplace_back(1);
	for(int i = 2; i * i <= x; i ++)
	{
		if(x % i == 0) 
		{
			nums.emplace_back(i);
			if(i * i != x) nums.emplace_back(x / i);
		}
	}

	bool st[60];
	int res = 0;
	memset(st, false, sizeof st);
	for(auto x : nums)
		res ^= sg(x);
	for(auto x : nums)
		st[res ^ sg(x)] = true;
	for(int i = 0; ; i ++)
	{
		if(!st[i]) return f[x] = i;
	}
	return 114514;
}

void solve()
{
	memset(f, -1, sizeof f);
	f[1] = 0;
	int n;
	while(cin >> n, n)
	{
		int ans = 0;
		for(int i = 1; i <= n; i ++)
		{
			int x;
			cin >> x;
			ans ^= sg(x);
		}
		cout << (ans ? "freda" : "rainbow") << '\n';
	}
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
}