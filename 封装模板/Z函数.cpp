#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

vector<int> getNext(string &T)
{
	int m = T.size();
	vector<int> ne(m);
	int l = 0, r = 1;
	ne[0] = m;
	for(int i = 1; i < m; i ++)
	{
		if(i < r && i + ne[i - l] < r)
		{
			ne[i] = ne[i - l];
		}
		else
		{
			if(i > r) r = i;
			while(r < m && T[r] == T[r - i]) r ++;
			ne[i] = r - i;
			l = i;
		}
	}
	return ne;
}

vector<int> getExtend(string &S, string &T)
{
	vector<int> ne = getNext(T);
	int n = S.size(), m = T.size();
	int l = 0, r = 0;
	vector<int> ex(n + 1);
	for(int i = 0; i < n; i ++)
	{
		if(i < r && i + ne[i - l] < r)
		{
			ex[i] = ne[i - l];
		}
		else
		{
			if(i > r) r = i;
			while(r < n && r - i < m && S[r] == T[r - i]) r ++;
			ex[i] = r - i;
			l = i;
		}
	}
	return ex;
}

void solve()
{
	string s, t;
	cin >> s >> t;
	vector<int> ne = getNext(t);
	vector<int> ex = getExtend(s, t);
	i64 res1 = 0, res2 = 0;
	for(int i = 0; i < t.size(); i ++)
		res1 ^= 1ll * (i + 1) * (ne[i] + 1);
	for(int i = 0; i < s.size(); i ++)
		res2 ^= 1ll * (i + 1) * (ex[i] + 1);
	cout << res1 << '\n' << res2 << '\n';
}

int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	// cin >> t;
	t = 1;
	while(t --)
	{
		solve();
	}
	return 0;
}