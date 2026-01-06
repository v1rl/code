#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110, inf = 1e9;

void solve()
{
	int n;
	cin >> n;
	i64 res = 0;
	for(int l = 1, r; l <= n; l = r + 1)
	{
		r = n / (n / l);
		res += (r - l + 1) * (n / l);
	}
	cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while(t --)
    {
    	solve();
    }
}