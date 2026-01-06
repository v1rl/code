#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;

// 0 1 1 0 1
// 1 1 1 1 0

void solve()
{
	int n;
	cin >> n;
	int lst = -1;
	bool f = false;

	vector<int> a(n + 1);
	for(int i = 1; i <= n; i ++)
		cin >> a[i];

	for(int i = 1; i <= n; i ++)
	{
		if(a[i] == 0) f = true;
		if(lst == 0 && a[i] == 0)
		{
			cout << "YES" << '\n';
			return;
		}
		lst = a[i];
	}
	if(!f) 
	{
		cout << "YES" << '\n';
	}
	else cout << "NO" << '\n';
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