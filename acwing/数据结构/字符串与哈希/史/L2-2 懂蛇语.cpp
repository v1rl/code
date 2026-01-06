#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;

void solve()
{
	int n;
	cin >> n;
	string _;
	getline(cin, _);
	map<string, vector<string>> mp;
	for(int i = 1; i <= n; i ++)
	{
		string s;
		getline(cin, s);
		string t = "";
		if(s[0] != ' ') t += s[0];
		for(int i = 1; i < s.size(); i ++)
		{
			if(s[i - 1] == ' ' && s[i] != ' ') t += s[i];
		}
		mp[t].emplace_back(s);
	}

	int m;
	cin >> m;
	getline(cin, _);
	for(int i = 1; i <= m; i ++)
	{
		string s;
		getline(cin, s);
		string t = "";
		t += s[0];
		for(int i = 1; i < s.size(); i ++)
		{
			if(s[i - 1] == ' ' && s[i] != ' ') t += s[i];
		}
		int p = mp[t].size();
		if(p > 0)
		{
			if(p == 1) cout << mp[t][0] << '\n';
			else
			{
				vector cur = mp[t];
				sort(cur.begin(), cur.end());
				for(int i = 0; i < p; i ++)
				{
					cout << cur[i];
					if(i != p - 1) cout << '|';
				}
				cout << '\n';
			}
		}
		else cout << s << '\n';
	}
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