#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110, inf = 1e9;

// https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?page=1&problemSetProblemId=1781658570803388420

void solve()
{
	int n;
	cin >> n;
	string _;
	string rp = "*_._._.*";
	getline(cin, _);
	vector<string> T(n + 1);
	for(int i = 1; i <= n; i ++)
	{
		getline(cin, T[i]);
	}
	int m;
	cin >> m;
	getline(cin, _);
	string S;
	getline(cin, S);
	int res = 0;
	for(int i = 1; i <= n; i ++)
	{
		int pos = 0;
		while(true)
		{
			pos = S.find(T[i], pos);
			if(pos == -1) break;
			S.replace(pos, T[i].size(), rp);
			pos += rp.size();
			res ++;
		}
	}
	if(res < m)
	{
		int pos = 0;
		string t = "<censored>";
		while(true)
		{
			pos = S.find(rp, pos);
			if(pos == -1) break;
			S.replace(pos, rp.size(), t);
			pos += t.size();
		}
		cout << S << '\n';
	}
	else
		cout << res << '\n' << "He Xie Ni Quan Jia!";
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
    	solve();
    }
}