#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 998244353;

// 固定行(2)--全连接行(2)--过渡连接行(3)

void solve()
{
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	string t(n, '#');
	int p = (s1 == t) + (s2 == t);
	if(p == 1)
	{
		cout << "No" << '\n';
		return;
	}
	else if(p == 2)
	{
		cout << "Yes" << '\n';
		for(int i = 1; i <= 7; i ++)
			cout << t << '\n';
		return;
	}

	cout << "Yes" << '\n';
	int pos1, pos2;
	for(int i = 0; i < n; i ++)
		if(s1[i] == '#' && ((i - 1 >= 0 && s1[i - 1] == '.') || (i + 1 < n && s1[i + 1] == '.')))
			pos1 = i;
	for(int i = 0; i < n; i ++)
		if(s2[i] == '#' && ((i - 1 >= 0 && s2[i - 1] == '.') || (i + 1 < n && s2[i + 1] == '.')))
			pos2 = i;

	cout << s1 << '\n';

	for(int i = 0; i < n; i ++)
	{
		if(s1[i] == '#') cout << '.';
		else cout << '#';
	}
	cout << '\n';

	for(int i = 0; i < n; i ++)
	{
		if(i == pos1) cout << '#';
		else cout << '.';
	}
	cout << '\n';

	if(abs(pos1 - pos2) <= 1)
	{
		for(int i = 0; i < n; i ++)
		{
			if(i == pos1) cout << '#';
			else cout << '.';
		}
	}
	else
	{
		for(int i = 0; i < n; i ++)
		{
			if(i > min(pos1, pos2) && i < max(pos1, pos2)) cout << '#';
			else cout << '.';
		}
	}
	cout << '\n';

	for(int i = 0; i < n; i ++)
	{
		if(i == pos2) cout << '#';
		else cout << '.';
	}
	cout << '\n';

	for(int i = 0; i < n; i ++)
	{
		if(s2[i] == '#') cout << '.';
		else cout << '#';
	}
	cout << '\n';

	cout << s2 << '\n';
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