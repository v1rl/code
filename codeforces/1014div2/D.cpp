#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n;
	cin >> n;
	string _;
	cin >> _;
	vector<int> a(4);
	string s = "";

	for(auto c : _)
	{
		if(c == 'T') s += '1', a[1] ++;
		else if(c == 'I') s += '2', a[2] ++;
		else s += '3', a[3] ++;
	}
	int o = 0;
	for(int i = 1; i <= 3; i ++)
	{
		if(a[i] == 0) o ++;
	}
	if(o >= 2)
	{
		cout << -1 << '\n';
		return;
	}

	vector<int> res;
	while(true)
	{
		int t = -1;
		int mn = 1e9;
		int mnn = 1e9;
		int ct = -1;
		for(int i = 1; i <= 3; i ++)
		{
			if(a[i] < mn)
			{
				mnn = mn;
				mn = a[i];

				ct = t;
				t = i;
			}
			else if(a[i] >= mn && a[i] < mnn)
			{
				mnn = a[i];
				ct = i;
			}
		}
		if(mn == a[1] && mn == a[2] && mn == a[3]) break;
		char ch = t + '0';
		bool f = false;
		for(int i = 0; i < s.size() - 1; i ++)
		{
			if(s[i] != ch && s[i + 1] != ch && s[i] != s[i + 1])
			{
				f = true;
				a[t] ++;
				string p = "";
				p += ch;
				s.insert(i + 1, p);
				res.emplace_back(i + 1);
				break;
			}
		}
		if(!f)
		{
			char cch = ct + '0';
			for(int i = 0; i < s.size() - 1; i ++)
			{
				if(s[i] != cch && s[i + 1] != cch && s[i] != s[i + 1])
				{
					a[ct] ++;
					string p = "";
					p += cch;
					s.insert(i + 1, p);
					res.emplace_back(i + 1);
					break;
				}
			}
		}
		// cout << s << '\n';
	}
	cout << res.size() << '\n';
	for(auto x : res)
		cout << x << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}