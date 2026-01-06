#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	for(int i = 0; i < n; i ++)
	{
		if(s1[i] != '1' && s2[i] != '1')
		{
			cout << 0 << '\n';
			return;
		}
	}
	cout << 1 << '\n';
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