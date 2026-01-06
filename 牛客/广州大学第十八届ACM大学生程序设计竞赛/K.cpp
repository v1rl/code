#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<char, int> mp;
	int x = 0, sum = 0;
	int p = 0;
	for(auto c : s)
	{
		if(x > 0)
		{
			x --;
			continue;
		}
		p ++;
		if(c == 'g' || c == 'z' || c == 'h' || c == 'u') mp[c] ++, sum ++;
		if(mp.size() == 4) x = sum, mp.clear(), sum = 0;
	}
	cout << p << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}
